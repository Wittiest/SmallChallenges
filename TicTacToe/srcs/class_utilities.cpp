// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   class_utilities.cpp                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/10/02 06:36:33 by dpearson          #+#    #+#             //
//   Updated: 2017/10/02 06:36:34 by dpearson         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "tictactoe.h"
#include <stdio.h>

void	Board::initialize_Board(void)
{
	int i = 0;

	while (i < 10)
	{
		tikboard[i] = i + '1';
		i++;
	}
}

void	Board::draw_Board(void)
{
	for (int i = 0; i < 9; i++)
	{
		cout << tikboard[i];
		if (((i + 1) % 3) == 0)
			cout << '\n';
	}	
}

void	Board::change_Spot(int spot, char mark)
{
	tikboard[spot - 1] = mark;
}

int	Board::is_Winner(void)
{
	char check;
	int i;

	for (i = 0; i < 3; i++) // check rows
	{
		check = tikboard[i];
		if (check != '.' && (tikboard[i + 1] == check) && (tikboard[i + 2] == check))
			return (1);
	}
	for (i = 0; i < 3; i++) // check columns
	{
		check = tikboard[i];
		if (check != '.' && (tikboard[i + 3] == check) && (tikboard[i + 6] == check))
			return (1);
	}
	if (tikboard[0] != '.' && (tikboard[0] == tikboard[4]) && (tikboard[0] == tikboard[8]))
		return (1);
	if (tikboard[2] != '.' && (tikboard[2] == tikboard[4]) && (tikboard[0] == tikboard[6]))
		return (1);	
	return (0);
}

int		Board::isValid(int move)
{
	if (move > 0 && move < 10)
		if (tikboard[move - 1] == ('0' + move))
			return (1);
	return (0);
}

void	Players::choose_Mark(void)
{
	cout << "Player 1, What character will be your mark?\n";
	cin >> p_one_mark;
	do
	{
		cout << "Player 2, What character will be your mark?\n";
		cin >> p_two_mark;
	} while (p_two_mark == p_one_mark);
	p_one_move = true;
	total_moves = 0;
}
void	Players::move(Board& board, int spot)
{
	board.change_Spot(spot, (p_one_move) ? p_one_mark : p_two_mark);
	p_one_move = !p_one_move;
	total_moves++;			
}
const char	*Players::get_Mover(void)
{
	return ((p_one_move) ? "Player One" : "Player Two");
}
