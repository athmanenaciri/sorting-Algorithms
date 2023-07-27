/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fordJhonsonSort.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:10:37 by anaciri           #+#    #+#             */
/*   Updated: 2023/07/27 02:28:53 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include<vector>

int	binarySearch(std::vector<int> vect, int left, int right, int key)
{
    while (left <= right)
	{
        int mid = left + (right - left) / 2;

        if (vect[mid] == key)
            return mid;
        else if (vect[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

void mergeInsertionSort(std::vector<int> &vect, int n)
{
    if (n <= 1)
        return;

    for (int i = 0; i < n - 1; i += 2)
	{
        if (vect[i] > vect[i + 1])
            std::swap(vect[i], vect[i + 1]);
    }

    mergeInsertionSort(vect, n / 2);
    for (int i = n / 2; i < n; i++)
	{
        int key = vect[i];
        int insertPos = binarySearch(vect, 0, i - 1, key);
        for (int j = i; j > insertPos; j--) {
            vect[j] = vect[j - 1];
        }
        vect[insertPos] = key;
    }
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

    int n = vect.size();

    std::cout << "unsorted list: ";
    for (int i = 0; i < n; i++)
        std::cout << vect[i] << " ";
    std::cout << std::endl;

    mergeInsertionSort(vect, n);

    std::cout << "Sorted list: ";
    for (int i = 0; i < n; i++)
        std::cout << vect[i] << " ";
    std::cout << std::endl;

    return 0;
}
