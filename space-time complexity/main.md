### Introduction to time complexity

Time complexity is a way to measure how long an algorithm takes to run as the amount of **input data** increases. Think of it as a method for figuring out how **fast or slow** an algorithm is.

There are multiple ways to measure time complexity of an algorithm:

1. Best case
2. Average case
3. Worst case

We will focus on understanding the **worst-case scenario** of how an algorithm performs. We use a special notation called “Big O notation” to talk about worst-case time complexity.
#### Why is Time Complexity important?

Time complexity of an algorithm is independent from the machine the algorithm is going to run on. Understanding time complexity is important because it gives us a way of **comparing algorithms** without worrying about the system on which the algorithms are going to run.

### Finding time complexity - Rule 1

To find out time complexity of an algorithm, we look at the number of operations performed based on the input size.

Let's take a look at the below code:

```python
a = 1
b = 2
print(a + b)
```

In the above algorithm, there is no input. In total three operations are being performed in three lines. Every single operation is denoted as O(1) (pronounced as Big O of 1).

Thus, for the above example, we have time complexity as `O(1) + O(1) + O(1) = 3 * O(1)`

But we denote the time complexity of the above algorithm as O(1), ignoring the constant 3.

#### Rule 1 - Ignore the constants

When calculating time complexity, we ignore the constant values because they don’t matter when the input size becomes large.

Thus O(1), 5 * O(1), 8 * O(1) are all O(1)


### Finding time complexity - O(N)

Let's look at another algorithm now.

```python
for i = 0 to N
    print(i)
```

In the above algorithm, we are running a loop from 0 to N. In total the loop will run **N** times. For each iteration of the loop we are doing one operation `print(i).

The final time complexity will be: N * O(1) => O(N).

This time the algorithm dependent on a variable N and with that the time complexity also has the value N.

