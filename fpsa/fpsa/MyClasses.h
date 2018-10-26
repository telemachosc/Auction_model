#pragma once
 

class SELLER
{
public:
	float energy_to_sell = 10000.0;
	float sale = 0;// per cent
	float to_receive = 0;
	float number_of_auctions = energy_to_sell / global::energy_per_auction;
	float energy_per_auction = global::energy_per_auction;
	float revenue = 0;

	void update_revenue()
	{
		revenue += to_receive;
		to_receive = 0;
	}

};

class SELLERS : public SELLER
{
public:
	int population;

	SELLER* name;
	SELLERS(int inp)
	{
		population = inp;
		name = new SELLER[population];
	}
	~SELLERS()
	{
		delete name;
	}


};

class BUYER
{
public:
	float total_paid = 0;
	float energy_to_buy;
	float bid_raise_coef = 1;
	float topay = 0;
	float energy_per_auction = global::energy_per_auction;// temporary
	float true_value = Urand(0.5, 1);//	U[0.5,1]
	float bid = true_value;// per energy	
	bool im_in;

	double budget;

	float total_offer()
	{
		return bid * energy_per_auction;
	}

	bool budgetiszero()
	{
		if (budget <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void update_budget()
	{
		total_paid += topay;
		budget -= topay;
		topay = 0;
	}

};

class BUYERS : public BUYER
{
public:
	int population;
	BUYER* name;
	int count_whose_in;


	BUYERS(int inp = 0)
	{
		population = inp;
		name = new BUYER[population];
	}

	~BUYERS()
	{
//		delete name;
	}

	int findwiner(int algo)
	{
		if (count_whose_in != 0)
		{
			int winner = NO_WINNER;


			switch (algo)
			{
			case BWIN_BIGEST_BID:// biggest bid wins
				for (int i = 0; i < population; i++)
				{

					if (this->name[i].im_in)
					{
						if (winner == NO_WINNER)
						{
							winner = i;
						}
						if (this->name[i].bid > this->name[winner].bid)
						{
							winner = i;
						}
					}
				}


				return winner;
				break;
			}
		}
		return NO_WINNER;
	}

	void update_bid(int algo, int winner, int max_auctions, int iauction)
	{
		switch (algo)
		{
		case BID_LINEAR:
			for (int i = 0; i < this->population; i++)
			{
				if (this->name[i].energy_to_buy > 0)
				{
					if (this->name[i].im_in)
					{
						this->name[i].bid = this->name[i].true_value;
					}
					else
					{
						this->name[i].bid = 0;
					}
				}
				else
				{
					this->name[i].bid = 0;
				}
			}
			break;
		case BID_MULT_COEF:
			if (winner != NO_WINNER)
			{
				for (int i = 0; i < this->population; i++)
				{
					this->name[i].bid_raise_coef = 1 + iauction / (float)max_auctions;
					if (i == winner)
					{
						this->name[i].bid_raise_coef = 0.5 + (1 - (iauction / (float)max_auctions))/2.0;
					}

					this->name[i].bid = this->name[i].bid * this->name[i].bid_raise_coef;
					if (this->name[i].bid < DEH_BUYS)
					{
						this->name[i].bid = DEH_BUYS;
					}
					else if(this->name[i].bid > DEH_SELLS)
					{
						this->name[i].bid = 0.99;
					}

				}
			}

			break;
		case BID_QUAD:

			break;
		case BID_EXP:

			break;
		}
	}

	void cout_all_bids()
	{
		for (int i = 0; i < this->population; i++)
		{
			std::cout << i << ' ' << this->name[i].bid << std::endl;
		}
	}

	void cout_all_total_offers()
	{
		for (int i = 0; i < this->population; i++)
		{
			std::cout << i << ' ' << this->name[i].total_offer() << std::endl;
		}
	}

	void cout_all_budget()
	{
		for (int i = 0; i < this->population; i++)
		{
			std::cout << i << ' ' << this->name[i].budget << std::endl;
		}
	}


};






