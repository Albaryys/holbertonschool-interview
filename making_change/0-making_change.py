#!/usr/bin/python3
"""Module used to add two arrays."""

def make_Change(coins, total):
    """
    Calculates the minimum number of coins needed to make change for a given total.

    Args:
        coins (list): A list of coin denominations available.
        total (int): The total amount to make change for.

    Returns:
        int: The minimum number of coins needed to make change for the total.
             Returns -1 if it is not possible to make change for the total.
    """
    
    if total < 0:
        return -1
    if total == 0:
        return 0
    
    dp = [float('inf')] * (total + 1)
    dp[0] = 0
    
    for i in range(1, total + 1):
        for coin in coins:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[total] if dp[total] != float('inf') else -1
