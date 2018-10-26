#pragma once




class AUCTION : public BUYERS, public SELLER
{
public:
	float auction_fee = 5;

	AUCTION()
	{
		//int numb_of_buyers;	   
		//int numb_of_sellers;   
		//int auction_type;
		//int bid_type;
		//int win_condition;

	}
	~AUCTION()
	{

	}

	
	void buyers_whose_in(SELLER s)
	{
		buyers.count_whose_in = 0;
		for (int i = 0; i < buyers.population; i++)
		{
			if (buyers.name[i].energy_to_buy >= s.energy_per_auction)
			{
				buyers.name[i].im_in = true;
				buyers.count_whose_in++;
			}
			else
			{
				buyers.name[i].im_in = false;
			}

		}
	}

	void init()
	{
		//////initialize sellers (ayto einai malakia prepei na to allaksoyme
		for (int i = 0; i < sellers.population; i++)
		{
			sellers.name[i].number_of_auctions = sellers.name[i].energy_to_sell / global::energy_per_auction;
			sellers.name[i].energy_per_auction = global::energy_per_auction;
			sellers.name[i].revenue = 0;
		}
		for (int i = 0; i < buyers.population; i++)
		{
			buyers.name[i].energy_per_auction = global::energy_per_auction;
			buyers.name[i].total_paid = 0;
		}
	}

	void losers_buy_from_deh()
	{
		for (int i = 0; i < buyers.population; i++)
		{
			if (buyers.name[i].energy_to_buy > 0)
			{
				buyers.name[i].topay = buyers.name[i].energy_to_buy * DEH_SELLS;
				buyers.name[i].update_budget();
				buyers.name[i].energy_to_buy = 0;
			}
		}
	}

	void begin()
	{

		this->init();


		switch (auction_type)
		{
		case AUCTION_SEALED:
			for (int iseller = 0; iseller < numb_of_sellers; iseller++)
			{
				int winner = NO_WINNER;
				for (int iauction = 0; iauction < sellers.name[iseller].number_of_auctions; iauction++)
				{
					buyers_whose_in(sellers.name[iseller]);
					buyers.update_bid(BID_MULT_COEF, winner, sellers.name[iseller].number_of_auctions, iauction);

	
					winner = buyers.findwiner(BWIN_BIGEST_BID);

					buyers.name[winner].topay = buyers.name[winner].total_offer();
					buyers.name[winner].topay += auction_fee;

					buyers.name[winner].energy_to_buy -= sellers.name[iseller].energy_per_auction;

					if (winner != NO_WINNER)
					{
						sellers.name[iseller].to_receive += buyers.name[winner].topay;


						sellers.name[iseller].update_revenue();
						buyers.name[winner].update_budget();
					
					}

				}
			
			}
			break;
		}




	}


private:

};

