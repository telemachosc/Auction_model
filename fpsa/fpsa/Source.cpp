// FPSA.cpp : Defines the entry point for the console application.
//

float *x_plot;
float *y_plot;

float *mean_seller_money_plot;
float *mean_num_of_auctions;

int iauction = 0;

float fakme[] = { 10000, 1000, 200, 100, 50, 20, 10, 5, 2, 1 };

#include "includes.h"
namespace global
{
	int energy_per_auction;
}
int numb_of_buyers = 20;
int numb_of_sellers = 1;
int auction_type = AUCTION_SEALED;
int bid_type = BID_LINEAR;
int win_condition = BWIN_BIGEST_BID;

#include "MyClasses.h"
#include "MyVariables.h"
#include "auction.h"
#include "MyFunctions.h"
#include <chrono>

#include "out_matlab.h"



int main()
{
	srand(1);
	
	Init();

	x_plot = new float[10];
	y_plot = new float[10];

	mean_seller_money_plot = new float[10];
	mean_num_of_auctions = new float[10];
	

	for (int i = 0; i < 10; i++)
	{
		mean_seller_money_plot[i] = 0;
		mean_num_of_auctions[i] = 0;
	}
	
	for (int i = 0; i < 10; i++)
	{
		y_plot[i] = 0;
	}

	AUCTION myauction;
	int j;

	for (j = 0; j < 5000; j++)
	{
		std::cout << j << std::endl;


		//std::cout << j << std::endl;
		for (iauction = 0; iauction < 10; iauction++)
		{
			Init();

			global::energy_per_auction = fakme[iauction];
			x_plot[iauction] = 10000 / global::energy_per_auction;



			myauction.begin();
			myauction.losers_buy_from_deh();

			for (int i = 0; i < numb_of_buyers; i++)
			{
				y_plot[iauction] += buyers.name[i].total_paid;
			}

		}



		//for (int i = 0; i < 10; i++)
		//{
		//	mean_seller_money_plot[i] += seller_money_plot[i];
		//	mean_num_of_auctions[i] += num_of_auctions[i];
		//}
	}

	for (int i = 0; i < 10; i++)
	{
		y_plot[i] = y_plot[i]/j;
		//x_plot[i] = x_plot[i]/j;

		//std::cout << mean_num_of_auctions[i] << " " << mean_seller_money_plot[i] << std::endl;
	}
	//getchar();
	write_matlab("aaaaaa.m", x_plot, y_plot, 10);



	//getchar();
	Finalize();

	
	return 0;
}

