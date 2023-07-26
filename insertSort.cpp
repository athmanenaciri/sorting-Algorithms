/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertSort.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:36:35 by anaciri           #+#    #+#             */
/*   Updated: 2023/07/26 11:26:07 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//implement the insert sort ;
//the program takes the numbers as arguments and sort them using insert sort
//
#include <iostream>
#include <vector>
#include <cctype>

std::vector<int>	insertSort(std::vector<int> vect)
{
	int j, tmp;
	for(int i = 1; i < vect.size();i++)
	{
		j = i;
		while(j > 0 && vect[j-1] > vect[j])
		{
			tmp = vect[j];
			vect[j] = vect[j-1];
			vect[j-1] = tmp;
			j--;
		}
	}
	return(vect);
}
int main(int ac, char **av)
{
    if (ac <= 2)
        return std::cout << "Error: number of arguments!\n", 1;

    int i = 1;
    std::vector<int> vect;
    while (i < ac)
    {
        int j = 0;
        while (av[i][j])
        {
            if (!isdigit(av[i][j]))
                return std::cout << "Error bad integer : " << av[i][j] << "\n", 1;
            j++;
        }
        int num = std::stoi(av[i]);
        vect.push_back(num);
        i++;
    }

    std::vector<int> res;
    res = insertSort(vect);
	std::cout << "unsorted list : ";
    for (size_t i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i] << " ";
    }
    std::cout << "\nsorted list : ";
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
