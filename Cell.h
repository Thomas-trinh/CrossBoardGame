/*
 * Cell.h
 *      Author: Hoang Tung
 */
#ifndef CELL_H_
#define CELL_H_

struct Cell
	{
		int x;
		int y;
		double heuristic;

		Cell(int x, int y, double v) : x(x), y(y), heuristic(v) {} // Constructor for Cell

		bool operator<(const Cell &c) const
		{
			return heuristic < c.heuristic;
		}
	};

#endif /* CELL_H_ */