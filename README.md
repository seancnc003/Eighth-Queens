# Eighth-Queens

The Eight Queens is a modified version of a classical problem and leetcode hard called N Queens. 
In the original version, the task is to put an N amount of Queens in an N by N chessboard in a way 
that they do no threaten each other. In this version, it's placing 8 Queens in an 8 by 8 chessboard.

This problem is solved through a programming technique called recursive backtracking. It is an algorithm
that takes a Big O notation time of N factorial and uses recursion.

The way it is done is by placing a queen on the chess board then going another row and trying to place
another queen. If no moves are available, you switch out your first move and place the queen in a different
column.

The C++ code is provided.
