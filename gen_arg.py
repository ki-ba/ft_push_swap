#!/usr/bin/env python3
import random

def generate_unique_integers(count, min_val=0, max_val=10):
    """
    Generate a list of unique random integers within a specified range.

    Args:
        count (int): Number of unique integers to generate
        min_val (int): Minimum value of the range (inclusive)
        max_val (int): Maximum value of the range (inclusive)

    Returns:
        list: Space-separated unique integers
    """
    if count > (max_val - min_val + 1):
        raise ValueError("Cannot generate more unique integers than available in the range")

    unique_numbers = random.sample(range(min_val, max_val + 1), count)
    return ' '.join(map(str, unique_numbers))

if __name__ == "__main__":
    print(generate_unique_integers(10))
