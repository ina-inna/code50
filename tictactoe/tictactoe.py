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
    x_count = 0
    o_count = 0
    if board == initial_state():
        return 'X'
    else:
        for row in board:
            for cell in row:
                if cell == 'X':
                    x_count += 1
                else if cell == 'O':
                    o_count += 1
    if x % 2 == 0:
        return 'X'
    else:
        return 'O'


def actions(board):
    """
    Returns the set of all possible actions (i, j) available on the board.

    check empty places on board
    include all empty moves to the set
    """

    moves = {}

    for i in range (3):
        for j in range (3):
            if board[i][j] is None:
                moves.add((i,j))
    return moves

def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    if action == None or action[0] < 0 or action[0] > 2 or action[1] < 0 or action[1] > 2:
        raise ValueError("Invalid action")
    else:
        new_board = copy.deepcopy(board)
        who_moves = player(board)
        new_board[action[0]][action[1]] = who_moves
        return new_board

def winner(board):
    """
    Returns the winner of the game, if there is one.

    if for any diagonal, horizontal or vertical, there is x or o, return x or o
    else: return none
    """
    def horizontal(board):
        return [row for row in board]
    def vertical(board):
        

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
