/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tictactoe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 05:35:48 by dpearson          #+#    #+#             */
/*   Updated: 2017/10/02 05:35:48 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>  // This is the standard input output library for C++
using namespace std; // Using this namespace means that when applicable, we will
					 // add std: before something like cout, because that is how
					 // it is referenced in the library.

class			Board
{
	char	tikboard[9];
	public:
		void	initialize_Board(void);
		void	draw_Board();
		void	change_Spot(int spot, char mark);
		int		check_Winner(void);
		int		isValid(int move);
};

class			Players
{
	char	p_one_mark;
	char	p_two_mark;
	bool	p_one_move;
	int		total_moves;
	public:
		void		choose_Mark(void);
		void		move(Board& board, int spot);
		const char	*get_Mover(void);
};


#endif
