#include<iostream>
#include<queue>

struct Cell
{
	int row;
	int column;
	int distance;

	Cell()
	{
		this->row = 0;
		this->column = 0;
		this->distance = 0;
	};
	Cell(int r, int c, int d)
	{
		this->row = r;
		this->column = c;
		this->distance = d;
	};
};
class Maze
{
public:
	Maze(int n, int m)
	{
		m_startCell = Cell(0, 0, 0);
		m_rowMaze = n;
		m_columnMaze = m;
		m_maze = new int*[n];
		for (int i = 0; i < n; i++)
		{
			m_maze[i] = new int[m];
			for (int j = 0; j < m; j++)
			{
				std::cin >> m_maze[i][j];
			}
		}
	};
	int FindShortestPath(int startPoint, int endPoint)
	{
		if (m_maze[0][0] || m_maze[startPoint][endPoint])
		{
			return -1;
		}

		std::queue<Cell> visitedCellss;
		std::vector<std::vector<bool>>v(m_rowMaze, std::vector<bool>(m_columnMaze, false));
		VisitCell(visitedCellss, m_startCell.row, m_startCell.column, 0, v);

		int row;
		int column;
		int distance;
		Cell currentCell;

		while (visitedCellss.empty() != true)
		{
			currentCell = visitedCellss.front();
			visitedCellss.pop();

			row = currentCell.row;
			column = currentCell.column;
			distance = currentCell.distance;

			if ((row < 0) || (row > m_rowMaze - 1) || (column < 0) || (column > m_columnMaze - 1))
			{
				return distance + 1;
			}
			if (row == startPoint && column == endPoint)
			{
				return distance;
			}
			VisitCell(visitedCellss, row, column + 1, distance + 1, v);
			VisitCell(visitedCellss, row, column - 1, distance + 1, v);
			VisitCell(visitedCellss, row + 1, column, distance + 1, v);
			VisitCell(visitedCellss, row - 1, column, distance + 1, v);
		}
		return -1;
	};
	void VisitCell(std::queue<Cell> &visitedCellss, int row, int column, int distance, std::vector<std::vector<bool>>& matrix)
	{
		if ((row < 0) || (row > m_rowMaze - 1) || (column < 0) || (column > m_columnMaze - 1))
		{
			return;
		}
		if (m_maze[row][column] != 1)
		{
			if (matrix[row][column] != true)
			{
				Cell cell = Cell(row, column, distance);
				visitedCellss.push(cell);
				matrix[row][column] = true;
			}
		}
	};
	~Maze()
	{
		for (int i = 0; i < m_rowMaze; i++)
		{
			delete[] m_maze[i];
		}
		delete[] m_maze;
	};

private:
	int** m_maze;
	int m_rowMaze;
	int m_columnMaze;
	Cell m_startCell;
};

int main()
{
	int n;
	int m;
	int k;
	std::cin >> n >> m >> k;

	int currenRow;
	int currenColumn;
	int currentDistance = 0;

	Maze maze(n, m);
	std::vector<int>distance;
	Cell startPosition(0, 0, 0);

	while (k > 0)
	{
		std::cin >> currenRow >> currenColumn;
		currentDistance = maze.FindShortestPath(currenRow, currenColumn);
		distance.push_back(currentDistance);

		k--;
	}

	for (int i = 0; i < distance.size(); i++)
	{
		std::cout << distance[i] << std::endl;
	}

	return 0;
}