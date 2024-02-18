"""
Tic Tac Toe Player
"""

import math

X = "X"
O = "O"
EMPTY = None


def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.

    if initial state, then x


    else:
    if x number is odd, then x, otherwise - o
    """
    if board == initial_state():
        return X
    
    raise NotImplementedError


def actions(board):
    """
    Returns the set of all possible actions (i, j) available on the board.

    check empty places on board
    include all empty moves to the set
    """
    raise NotImplementedError


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.

    if action in not valid: not on empty sell within the bound of the board, return error

    for X or O, return a deep copy with i,j move
    """
    raise NotImplementedError


def winner(board):
    """
    Returns the winner of the game, if there is one.

    if for any diagonal, horizontal or vertical, there is x or o, return x or o
    else: return none
    """
    raise NotImplementedError


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    return true if all cells are filled or if there is a winner,
    else: return false

    """
    raise NotImplementedError


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.

    call winner function to return a winner
    if x, then 1
    if o, then -1
    else: 0

    """
    raise NotImplementedError


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    raise NotImplementedError
