#pragma once

template <typename T>
bool FindMax(std::vector<T> const &arr, T &maxValue)
{
	return FindMax(arr, maxValue, std::less<T>());
}

template <typename T, typename Less>
bool FindMax(std::vector<T> const &arr, T &maxValue, Less const &less)
{
	if (arr.empty())
	{
		return false;
	}
	auto value = arr.begin();
	
	for (auto it = arr.begin() + 1; it != arr.end(); it++)
	{
		if (less(*value, *it))
		{
<<<<<<< HEAD
			value = it;
=======
			value = *it;
>>>>>>> origin/master
		}
	}
	maxValue = *value;
	return true;
}