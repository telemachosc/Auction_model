#pragma once

std::string matlab_graph = "loglog";
std::string xlabel = "N aution";
std::string ylabel = "mean paid of buyers";

void write_matlab(std::string out, float* x, float* y, int N)
{// plot number of auctions =f(revenue)
	std::ofstream file;
	file.open(out);

	file << "clear all\n";
	file << "close all\n";
	
	file << " x = [";
	for (int i = 0; i < N - 1; i++)
	{
		file << x[i] << ", ";
	}
	file << x[N - 1] << "];\n";

	file << " y = [";
	for (int i = 0; i < N - 1; i++)
	{
		file << y[i] << ", ";
	}
	file << y[N - 1] << "];\n";

	file << " y = y-x*5;" << std::endl;
	file << matlab_graph << "(x,y,'*-')\n";
	file << "grid on\n";
	file << "xlabel('" << xlabel << "')\n";
	file << "ylabel('" << ylabel << "')\n";


	file.close();

}

