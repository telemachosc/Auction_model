#pragma once




void Init()
{
	std::cout.precision(16);



	for (int i = 0; i < numb_of_buyers; i++)
	{
		buyers.name[i].energy_to_buy = Urand(10000,10000);
		//std::cout << buyers.name[i].energy_to_buy << std::endl;
		buyers.name[i].budget = 1000000000;
	}



}

void Finalize()
{
}


