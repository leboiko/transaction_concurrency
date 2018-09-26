
# transaction_concurrency
Go to the folder and type Make in order to generate the needed files.
It will generate a file named "escalona". The usage is simple:

It expects a file like the transactions.in, with values separated by a space, indicating the 
time, the transaction ID, the operation (R, W, C) and the variable to be modified.

The code tests whether the transactions can be executed in parallel or may be executed serially.  

./escalona < transactionsPack > results.out


