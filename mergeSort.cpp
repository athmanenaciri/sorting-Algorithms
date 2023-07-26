/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:36:35 by anaciri           #+#    #+#             */
/*   Updated: 2023/07/26 10:38:25 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//implement the merge sort ;
//the program takes the numbers as arguments and sort them using merge sort (devide & conquer)
//
#include <iostream>
#include <vector>
#include <cctype>

std::vector<int> merge(std::vector<int> vectOne, std::vector<int> vectTwo)
{
    std::vector<int> vectThree;

    while (!vectOne.empty() && !vectTwo.empty())
    {
        if (vectOne[0] > vectTwo[0])
        {
            vectThree.push_back(vectTwo[0]);
            vectTwo.erase(vectTwo.begin());
        }
        else
        {
            vectThree.push_back(vectOne[0]);
            vectOne.erase(vectOne.begin());
        }
    }

    while (!vectOne.empty())
    {
        vectThree.push_back(vectOne[0]);
        vectOne.erase(vectOne.begin());
    }

    while (!vectTwo.empty())
    {
        vectThree.push_back(vectTwo[0]);
        vectTwo.erase(vectTwo.begin());
    }

    return vectThree;
}

std::vector<int> mergeSort(std::vector<int> vect)
{
    if (vect.size() <= 1)
        return vect;

    std::vector<int> vectOne;
    std::vector<int> vectTwo;

    for (int i = 0; i < vect.size() / 2; i++)
        vectOne.push_back(vect[i]);

    for (int i = vect.size() / 2; i < vect.size(); i++)
        vectTwo.push_back(vect[i]);

    vectOne = mergeSort(vectOne);
    vectTwo = mergeSort(vectTwo);

    return merge(vectOne, vectTwo);
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
    res = mergeSort(vect);
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
