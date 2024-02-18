"""
Tic Tac Toe Player
"""

import copy
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
    """
    count = 0
    if board == initial_state():
        return 'X'
    else:
        for row in board:
            for cell in row:
                if cell == 'X' or cell == 'O':
                    count += 1
    if count % 2 == 0:
        return 'X'
    else:
        return 'O'


def actions(board):
    """
    Returns the set of all possible actions (i, j) available on the board.
    """

    moves = set()

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
    """
    array_of_results = check_board(board)
    print(array_of_results)
    for result in array_of_results:
        if result == ['X', 'X', 'X']:
            return 'X'
        elif result == ['O', 'O', 'O']:
            return 'O'

    return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    if winner(board) == 'X' or winner(board) == 'O':
        return True
    elif allCellsFilled(board) == True:
        return True

    return False


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    if winner(board) == X:
        return 1
    elif winner(board) == O:
        return -1
    else:
        return 0

def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    raise NotImplementedError


def check_board(board):
    results = []
    results.append(board)
    results.append(vertical(board))
    results.append(diagonal1(board))
    results.append(diagonal2(board))
    return results


def vertical(board):
    return [[board[j][i] for j in range(len(board))] for i in range(len(board[0]))]

def diagonal1(board):
    return [board[i][i] for i in range(len(board))]

def diagonal2(board):
    return [board[i][len(board) - 1 - i] for i in range(len(board))]

def allCellsFilled(board):
    count = 0
    for row in board:
        for cell in row:
            if cell == None:
                count += 1
    if count == 0:
        return True
    else:
        return False

