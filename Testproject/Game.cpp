#include "stdafx.h"
#include "Game.h"
#include "string"
#include <vector>
#include "Board.h"
#include <windows.h>
#include <iostream>

using namespace std;

Game::Game()
{
	if (delay) // SHOW MY EPIC CHESS BANNER ^_^ ASCII ART FTW
	{
		const char* banner = "C://Users//joeri//Desktop//Test//Testproject//banner.txt";
		reader.open(banner);
		printString = getbanner(reader);
		cout << printString << endl;
		reader.close();
		getchar();
		delay = false;
	}

	
	newstartselect = new Startselect();
	newboard = new Board();  // Define newboard to the board class 
	
	const char* banner = "banner.txt";
	reader.open(banner);
	printString = getbanner(reader);
	cout << printString << endl;
	reader.close();

	

	//////////// --------------- INITIALISATION PIECES MOVEMENT AND CATCH OPTIONS IN STARTBOARD -------------- \\\\\\\\\\\\\\\	

	StartBoard.push_back(new Pieces{ "Black", "Rook", 'a', 1 ,Pieces::MoveOptions::HorizontalAndVertical, Pieces::CatchOptions::Straight, 7 });
	StartBoard.push_back(new Pieces{ "Black", "Horse", 'b', 1 ,Pieces::MoveOptions::weirdhorsemove, Pieces::CatchOptions::weirdhorsecatch , 2 });
	StartBoard.push_back(new Pieces{ "Black", "Bishop", 'c', 1 ,Pieces::MoveOptions::Schuin2, Pieces::CatchOptions::Schuin , 7 });
	StartBoard.push_back(new Pieces{ "Black", "Queen", 'd', 1 ,Pieces::MoveOptions::alldirections, Pieces::CatchOptions::allaround , 7 });
	StartBoard.push_back(new Pieces{ "Black", "King", 'e', 1 ,Pieces::MoveOptions::alldirections, Pieces::CatchOptions::allaround , 1 });
	StartBoard.push_back(new Pieces{ "Black", "Bishop", 'f', 1 ,Pieces::MoveOptions::Schuin2, Pieces::CatchOptions::Schuin , 7 });
	StartBoard.push_back(new Pieces{ "Black", "Horse", 'g', 1 ,Pieces::MoveOptions::weirdhorsemove, Pieces::CatchOptions::weirdhorsecatch , 2 });
	StartBoard.push_back(new Pieces{ "Black", "Rook", 'h', 1 ,Pieces::MoveOptions::HorizontalAndVertical, Pieces::CatchOptions::Straight , 7 });

	StartBoard.push_back(new Pieces{ "Black", "Pawn", 'a', 2 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin,  1 });
	StartBoard.push_back(new Pieces{ "Black", "Pawn", 'b', 2 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "Black", "Pawn", 'c', 2 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "Black", "Pawn", 'd', 2 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "Black", "Pawn", 'e', 2 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "Black", "Pawn", 'f', 2 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "Black", "Pawn", 'g', 2 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "Black", "Pawn", 'h', 2 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });

	StartBoard.push_back(new Pieces{ "White", "Rook", 'a', 8 ,Pieces::MoveOptions::HorizontalAndVertical, Pieces::CatchOptions::Straight , 7 });
	StartBoard.push_back(new Pieces{ "White", "Horse", 'b', 8 ,Pieces::MoveOptions::weirdhorsemove, Pieces::CatchOptions::weirdhorsecatch , 2 });
	StartBoard.push_back(new Pieces{ "White", "Bishop", 'c', 8 ,Pieces::MoveOptions::Schuin2, Pieces::CatchOptions::Schuin , 7 });
	StartBoard.push_back(new Pieces{ "White", "Queen", 'd', 8 ,Pieces::MoveOptions::alldirections, Pieces::CatchOptions::allaround , 7 });
	StartBoard.push_back(new Pieces{ "White", "King", 'e', 8,Pieces::MoveOptions::alldirections, Pieces::CatchOptions::allaround , 1 });
	StartBoard.push_back(new Pieces{ "White", "Bishop", 'f', 8 ,Pieces::MoveOptions::Schuin2, Pieces::CatchOptions::Schuin , 7 });
	StartBoard.push_back(new Pieces{ "White", "Horse", 'g', 8 ,Pieces::MoveOptions::weirdhorsemove, Pieces::CatchOptions::weirdhorsecatch , 2 });
	StartBoard.push_back(new Pieces{ "White", "Rook", 'h', 8 ,Pieces::MoveOptions::HorizontalAndVertical, Pieces::CatchOptions::Straight , 7 });

	StartBoard.push_back(new Pieces{ "White", "Pawn", 'a', 7 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "White", "Pawn", 'b', 7 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "White", "Pawn", 'c', 7 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "White", "Pawn", 'd', 7 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "White", "Pawn", 'e', 7 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "White", "Pawn", 'f', 7 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "White", "Pawn", 'g', 7 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });
	StartBoard.push_back(new Pieces{ "White", "Pawn", 'h', 7 ,Pieces::MoveOptions::VerticalCantMoveBack, Pieces::CatchOptions::Schuin , 1 });


	newboard->generateBoard(StartBoard);
	playerturn = newstartselect->player;

	while (game)  // Start of the game 
	{
		if (playerturn)  // player one
		{
			cout << "" << endl;
			cout << newstartselect->PlayerOne.Name << " " << "please give"<< endl;
			cout << "Pion on Location" << endl;  // input current location
			cin >> location;
			cout << "Move to location" << endl; //  input new location
			cin >> newlocation;
		}

		///// ------------------ BLACK PIECES --------------------------- \\\\\\

		for (size_t i = 0; i < StartBoard.size(); i++)
		{
			if (StartBoard[i]->x == location[0] && StartBoard[i]->y == location[1] - '0')
			{
				if (StartBoard[i]->pieceType == "Black" && playerturn)   
				{
					
					/////////////  ----------  PAWN MOVEMENT -------------- \\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::VerticalCantMoveBack && StartBoard[i]->pieceName == "Pawn")
					{
						if (newlocation[1] > location[1] && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0])
						{
							bool foundObject = false;
							for (size_t a = 0; a < StartBoard.size(); a++)
							{
								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject = true;
								}
							}

							if (!foundObject)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = false;
							}
						}
						if (StartBoard[i]->catchOption == Pieces::CatchOptions::Schuin)
						{
							if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[0] - newlocation[0] != 0 && newlocation[1] > location[1] && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves)
							{
								for (size_t a = 0; a < StartBoard.size(); a++)
								{
									if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
									{
										StartBoard[i]->x = newlocation[0];
										StartBoard[i]->y = newlocation[1] - '0';

										StartBoard[a]->x = 'k';
										StartBoard[a]->y = 1;
										StartBoard[a]->pieceName = "dead";
										playerturn = false;
									}
								}
							}
						}
					}
					
					//////////// ------------- ROOK MOVEMENT ---------------- \\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::HorizontalAndVertical && StartBoard[i]->pieceName == "Rook")
					{

						if (abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0])
						{
							bool foundObject2 = false;
							bool foundObstacke = false;
							if ((location[1] - '0') - (newlocation[1] - '0') > 0)
							{
								for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[1] - '0') - (newlocation[1] - '0') < 0)
							{
								for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}

							for (size_t a = 0; a < StartBoard.size(); a++)
							{

								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject2 = true;

								}
							}

							if (!foundObject2)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = false;
							}
							if (StartBoard[i]->catchOption == Pieces::CatchOptions::Straight && !foundObstacke)
							{
								if (abs((location[1] - '0') - (newlocation[1] - '0')) <= StartBoard[i]->maxMoves && location[1] - newlocation[1] != 0 && newlocation[0] - location[0] == 0)
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = false;
										}
									}
								}
							}
						}
						if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1])
						{
							bool foundObject3 = false;
							bool foundObstacke = false;
							if ((location[0] - '0') - (newlocation[0] - '0') > 0)
							{
								for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == newlocation[1] - '0' && StartBoard[b]->x == '0' + (char)a)
										{
											foundObject3 = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') < 0)
							{
								for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == newlocation[1] - '0'  && StartBoard[b]->x == '0' + (char)a)
										{
											foundObject3 = true;
											foundObstacke = true;

										}
									}

								}
							}
							for (size_t a = 0; a < StartBoard.size(); a++)
							{

								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject3 = true;

								}
							}

							if (!foundObject3)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = false;
							}
							if (abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] - newlocation[0] != 0 && newlocation[1] - location[1] == 0)
							{
								for (size_t a = 0; a < StartBoard.size(); a++)
								{
									if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
									{
										StartBoard[i]->x = newlocation[0];
										StartBoard[i]->y = newlocation[1] - '0';

										StartBoard[a]->x = 'k';
										StartBoard[a]->y = 1;
										StartBoard[a]->pieceName = "dead";
										playerturn = false;
									}
								}
							}
							if (StartBoard[i]->catchOption == Pieces::CatchOptions::Straight && !foundObstacke)
							{
								if (abs((location[0] - '0') - (newlocation[0] - '0')) <= StartBoard[i]->maxMoves && location[0] - newlocation[0] != 0 && newlocation[1] - location[1] == 0)
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = false;
										}
									}
								}
							}

						}
					}
					
					//////////// ------------- BISHOP MOVEMENT -------------- \\\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::Schuin2 && StartBoard[i]->pieceName == "Bishop")
					{
						if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves)
						{
							bool foundObject2 = false;
							bool foundObstacke = false;
							if ((location[1] - '0') - (newlocation[1] - '0') > 0 && (location[0] - '0') - (newlocation[0] - '0') > 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}

							// schuin benede links
							if ((location[1] - '0') - (newlocation[1] - '0') < 0 && (location[0] - '0') - (newlocation[0] - '0') < 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject2 = true;
											foundObstacke = true;
										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') > 0 && (location[1] - '0') - (newlocation[1] - '0') > 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->y == (char)c) && (StartBoard[b]->x == '0' + (char)a))
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') < 0 && (location[1] - '0') - (newlocation[1] - '0') < 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == (char)c  && StartBoard[b]->x == '0' + (char)a + 1)
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}
							for (size_t a = 0; a < StartBoard.size(); a++)
							{
								if ((StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject2 = true;
								}
							}

							if (!foundObject2)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = false;
							}
							if (StartBoard[i]->catchOption == Pieces::CatchOptions::Schuin && !foundObstacke)
							{
								if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[0] - newlocation[0] != 0 && newlocation[1] > location[1] && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves)
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = false;
										}
									}
								}
							}
						}
					}
					
					//////////// ------------- KING MOVEMENT -------------- \\\\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::alldirections && StartBoard[i]->pieceName == "King")
					{
						if ((abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0]) ||
							(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1]) ||
							(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves))
						{
							bool foundObject = false;
							bool foundObstacke = false;

							if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1])
							{
								if ((location[0] - '0') - (newlocation[0] - '0') > 0)
								{
									for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->y == newlocation[1] - '0' && StartBoard[b]->x == '0' + (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
								if ((location[0] - '0') - (newlocation[0] - '0') < 0)
								{
									for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->y == newlocation[1] - '0'  && StartBoard[b]->x == '0' + (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
							}
							if (abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0])
							{
								if ((location[1] - '0') - (newlocation[1] - '0') > 0)
								{
									for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
								if ((location[1] - '0') - (newlocation[1] - '0') < 0)
								{
									for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
							}
							if ((location[1] - '0') - (newlocation[1] - '0') > 0 && (location[0] - '0') - (newlocation[0] - '0') > 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}

							// schuin benede links
							if ((location[1] - '0') - (newlocation[1] - '0') < 0 && (location[0] - '0') - (newlocation[0] - '0') < 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject = true;
											foundObstacke = true;
										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') > 0 && (location[1] - '0') - (newlocation[1] - '0') > 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->y == (char)c) && (StartBoard[b]->x == '0' + (char)a))
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') < 0 && (location[1] - '0') - (newlocation[1] - '0') < 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == (char)c  && StartBoard[b]->x == '0' + (char)a + 1)
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							for (size_t a = 0; a < StartBoard.size(); a++)
							{
								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject = true;
								}
							}

							if (!foundObject)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = false;
							}

							if (StartBoard[i]->catchOption == Pieces::CatchOptions::allaround)
							{
								if ((abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0]) ||
									(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1]) ||
									(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves))
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = false;
										}
									}
								}
							}
						}

					}
					
					//////////// ------------- QUEEN MOVEMENT -------------- \\\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::alldirections && StartBoard[i]->pieceName == "Queen")
					{
						if ((abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0]) ||
							(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1]) ||
							(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves))
						{
							bool foundObject = false;
							bool foundObstacke = false;

							if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1])
							{
								if ((location[0] - '0') - (newlocation[0] - '0') > 0)
								{
									for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->y == newlocation[1] - '0' && StartBoard[b]->x == '0' + (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
								if ((location[0] - '0') - (newlocation[0] - '0') < 0)
								{
									for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->y == newlocation[1] - '0'  && StartBoard[b]->x == '0' + (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
							}
							if (abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0])
							{
								if ((location[1] - '0') - (newlocation[1] - '0') > 0)
								{
									for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
								if ((location[1] - '0') - (newlocation[1] - '0') < 0)
								{
									for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
							}
							if ((location[1] - '0') - (newlocation[1] - '0') > 0 && (location[0] - '0') - (newlocation[0] - '0') > 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[1] - '0') - (newlocation[1] - '0') < 0 && (location[0] - '0') - (newlocation[0] - '0') < 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject = true;
											foundObstacke = true;
										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') > 0 && (location[1] - '0') - (newlocation[1] - '0') > 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->y == (char)c) && (StartBoard[b]->x == '0' + (char)a))
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') < 0 && (location[1] - '0') - (newlocation[1] - '0') < 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == (char)c  && StartBoard[b]->x == '0' + (char)a + 1)
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							for (size_t a = 0; a < StartBoard.size(); a++)
							{
								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject = true;
								}
							}

							if (!foundObject)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = false;
							}

							if (StartBoard[i]->catchOption == Pieces::CatchOptions::allaround)
							{
								if ((abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0]) ||
									(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1]) ||
									(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves))
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = false;
										}
									}
								}
							}
						}
					}

					/////////// -------------- HORSE MOVEMENT -------------- \\\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::weirdhorsemove && StartBoard[i]->pieceName == "Horse")
					{
						if ((abs(location[1] - newlocation[1]) == StartBoard[i]->maxMoves && abs(location[0] -  newlocation[0]) == 1) ||
							(abs(location[0] - newlocation[0]) == StartBoard[i]->maxMoves && abs(location[1]  - newlocation[1]) == 1))
						{
							bool foundObject = false;

							for (size_t a = 0; a < StartBoard.size(); a++)
							{

								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject = true;

								}
							}
													
							if (!foundObject)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = false;
							}
							if (StartBoard[i]->catchOption == Pieces::CatchOptions::weirdhorsecatch)
							{
								for (size_t a = 0; a < StartBoard.size(); a++)
								{
									if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
									{
										StartBoard[i]->x = newlocation[0];
										StartBoard[i]->y = newlocation[1] - '0';

										StartBoard[a]->x = 'k';
										StartBoard[a]->y = 1;
										StartBoard[a]->pieceName = "dead";
										playerturn = false;
									}
								}
							}
						}
					}
				}
			}
		}

		newboard->generateBoard(StartBoard);
		
		if (!playerturn)  // Player 2 
		{
			cout << "" << endl;
			cout << newstartselect->PlayerTwo.Name <<" "<< "please give" << endl;
			cout << "Pion on Location" << endl;
			cin >> location;
			cout << "Move to location" << endl;
			cin >> newlocation;
		}

		///// ------------- WHITE PIECES ---------------  \\\\\\

		for (size_t i = 0; i < StartBoard.size(); i++)  
		{
			if (StartBoard[i]->x == location[0] && StartBoard[i]->y == location[1] - '0')
			{
				if (StartBoard[i]->pieceType == "White" && !playerturn)   ///// ------------- WHITE PIECES --------------- 
				{
					/////////////  ----------  PAWN MOVEMENT -------------- \\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::VerticalCantMoveBack && StartBoard[i]->pieceName == "Pawn")
					{
						if (newlocation[1] < location[1] && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0])
						{
							bool foundObject = false;
							for (size_t a = 0; a < StartBoard.size(); a++)
							{
								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject = true;
								}
							}

							if (!foundObject)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = true;
							}
						}
						if (StartBoard[i]->catchOption == Pieces::CatchOptions::Schuin)
						{
							if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[0] - newlocation[0] != 0 && newlocation[1] > location[1] && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves)
							{
								for (size_t a = 0; a < StartBoard.size(); a++)
								{
									if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
									{
										StartBoard[i]->x = newlocation[0];
										StartBoard[i]->y = newlocation[1] - '0';

										StartBoard[a]->x = 'k';
										StartBoard[a]->y = 1;
										StartBoard[a]->pieceName = "dead";
										playerturn = true;
									}
								}
							}
						}
					}

					//////////// ------------- ROOK MOVEMENT ---------------- \\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::HorizontalAndVertical && StartBoard[i]->pieceName == "Rook")
					{

						if (abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0])
						{
							bool foundObject2 = false;
							bool foundObstacke = false;
							if ((location[1] - '0') - (newlocation[1] - '0') > 0)
							{
								for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[1] - '0') - (newlocation[1] - '0') < 0)
							{
								for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}

							for (size_t a = 0; a < StartBoard.size(); a++)
							{

								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject2 = true;

								}
							}

							if (!foundObject2)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = true;
							}
							if (StartBoard[i]->catchOption == Pieces::CatchOptions::Straight && !foundObstacke)
							{
								if (abs((location[1] - '0') - (newlocation[1] - '0')) <= StartBoard[i]->maxMoves && location[1] - newlocation[1] != 0 && newlocation[0] - location[0] == 0)
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = true;
										}
									}
								}
							}
						}
						if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1])
						{
							bool foundObject3 = false;
							bool foundObstacke = false;
							if ((location[0] - '0') - (newlocation[0] - '0') > 0)
							{
								for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == newlocation[1] - '0' && StartBoard[b]->x == '0' + (char)a)
										{
											foundObject3 = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') < 0)
							{
								for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == newlocation[1] - '0'  && StartBoard[b]->x == '0' + (char)a)
										{
											foundObject3 = true;
											foundObstacke = true;

										}
									}

								}
							}
							for (size_t a = 0; a < StartBoard.size(); a++)
							{

								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject3 = true;

								}
							}

							if (!foundObject3)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = true;
							}
							if (abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] - newlocation[0] != 0 && newlocation[1] - location[1] == 0)
							{
								for (size_t a = 0; a < StartBoard.size(); a++)
								{
									if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
									{
										StartBoard[i]->x = newlocation[0];
										StartBoard[i]->y = newlocation[1] - '0';

										StartBoard[a]->x = 'k';
										StartBoard[a]->y = 1;
										StartBoard[a]->pieceName = "dead";
										playerturn = true;
									}
								}
							}
							if (StartBoard[i]->catchOption == Pieces::CatchOptions::Straight && !foundObstacke)
							{
								if (abs((location[0] - '0') - (newlocation[0] - '0')) <= StartBoard[i]->maxMoves && location[0] - newlocation[0] != 0 && newlocation[1] - location[1] == 0)
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = true;
										}
									}
								}
							}

						}
					}

					//////////// ------------- BISHOP MOVEMENT -------------- \\\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::Schuin2 && StartBoard[i]->pieceName == "Bishop")
					{
						if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves)
						{
							bool foundObject2 = false;
							bool foundObstacke = false;
							if ((location[1] - '0') - (newlocation[1] - '0') > 0 && (location[0] - '0') - (newlocation[0] - '0') > 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}

							// schuin benede links
							if ((location[1] - '0') - (newlocation[1] - '0') < 0 && (location[0] - '0') - (newlocation[0] - '0') < 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject2 = true;
											foundObstacke = true;
										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') > 0 && (location[1] - '0') - (newlocation[1] - '0') > 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->y == (char)c) && (StartBoard[b]->x == '0' + (char)a))
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') < 0 && (location[1] - '0') - (newlocation[1] - '0') < 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == (char)c  && StartBoard[b]->x == '0' + (char)a + 1)
										{
											foundObject2 = true;
											foundObstacke = true;

										}
									}

								}
							}
							for (size_t a = 0; a < StartBoard.size(); a++)
							{
								if ((StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject2 = true;
								}
							}

							if (!foundObject2)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = true;
							}
							if (StartBoard[i]->catchOption == Pieces::CatchOptions::Schuin && !foundObstacke)
							{
								if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[0] - newlocation[0] != 0 && newlocation[1] > location[1] && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves)
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = true;
										}
									}
								}
							}
						}
					}

					//////////// ------------- KING MOVEMENT -------------- \\\\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::alldirections && StartBoard[i]->pieceName == "King")
					{
						if ((abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0]) ||
							(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1]) ||
							(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves))
						{
							bool foundObject = false;
							bool foundObstacke = false;

							if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1])
							{
								if ((location[0] - '0') - (newlocation[0] - '0') > 0)
								{
									for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->y == newlocation[1] - '0' && StartBoard[b]->x == '0' + (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
								if ((location[0] - '0') - (newlocation[0] - '0') < 0)
								{
									for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->y == newlocation[1] - '0'  && StartBoard[b]->x == '0' + (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
							}
							if (abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0])
							{
								if ((location[1] - '0') - (newlocation[1] - '0') > 0)
								{
									for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
								if ((location[1] - '0') - (newlocation[1] - '0') < 0)
								{
									for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
							}
							if ((location[1] - '0') - (newlocation[1] - '0') > 0 && (location[0] - '0') - (newlocation[0] - '0') > 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}

							// schuin benede links
							if ((location[1] - '0') - (newlocation[1] - '0') < 0 && (location[0] - '0') - (newlocation[0] - '0') < 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject = true;
											foundObstacke = true;
										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') > 0 && (location[1] - '0') - (newlocation[1] - '0') > 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->y == (char)c) && (StartBoard[b]->x == '0' + (char)a))
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') < 0 && (location[1] - '0') - (newlocation[1] - '0') < 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == (char)c  && StartBoard[b]->x == '0' + (char)a + 1)
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							for (size_t a = 0; a < StartBoard.size(); a++)
							{
								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject = true;
								}
							}

							if (!foundObject)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = true;
							}

							if (StartBoard[i]->catchOption == Pieces::CatchOptions::allaround)
							{
								if ((abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0]) ||
									(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1]) ||
									(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves))
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = true;
										}
									}
								}
							}
						}

					}

					//////////// ------------- QUEEN MOVEMENT -------------- \\\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::alldirections && StartBoard[i]->pieceName == "Queen")
					{
						if ((abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0]) ||
							(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1]) ||
							(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves))
						{
							bool foundObject = false;
							bool foundObstacke = false;

							if (abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1])
							{
								if ((location[0] - '0') - (newlocation[0] - '0') > 0)
								{
									for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->y == newlocation[1] - '0' && StartBoard[b]->x == '0' + (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
								if ((location[0] - '0') - (newlocation[0] - '0') < 0)
								{
									for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->y == newlocation[1] - '0'  && StartBoard[b]->x == '0' + (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
							}
							if (abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0])
							{
								if ((location[1] - '0') - (newlocation[1] - '0') > 0)
								{
									for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
								if ((location[1] - '0') - (newlocation[1] - '0') < 0)
								{
									for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++)
									{
										for (size_t b = 0; b < StartBoard.size(); b++)
										{
											if (StartBoard[b]->x == newlocation[0] && StartBoard[b]->y == (char)a)
											{
												foundObject = true;
												foundObstacke = true;

											}
										}

									}
								}
							}
							if ((location[1] - '0') - (newlocation[1] - '0') > 0 && (location[0] - '0') - (newlocation[0] - '0') > 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' - 1; a > newlocation[1] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[1] - '0') - (newlocation[1] - '0') < 0 && (location[0] - '0') - (newlocation[0] - '0') < 0)
							{
								size_t c = location[0] - '0' + 1;
								for (size_t a = location[1] - '0' + 1; a < newlocation[1] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->x == '0' + (char)c) && (StartBoard[b]->y == (char)a))
										{
											foundObject = true;
											foundObstacke = true;
										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') > 0 && (location[1] - '0') - (newlocation[1] - '0') > 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' - 1; a > newlocation[0] - '0'; a--, c--)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if ((StartBoard[b]->y == (char)c) && (StartBoard[b]->x == '0' + (char)a))
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							if ((location[0] - '0') - (newlocation[0] - '0') < 0 && (location[1] - '0') - (newlocation[1] - '0') < 0)
							{
								size_t c = location[1] + 1;
								for (size_t a = location[0] - '0' + 1; a < newlocation[0] - '0'; a++, c++)
								{
									for (size_t b = 0; b < StartBoard.size(); b++)
									{
										if (StartBoard[b]->y == (char)c  && StartBoard[b]->x == '0' + (char)a + 1)
										{
											foundObject = true;
											foundObstacke = true;

										}
									}

								}
							}
							for (size_t a = 0; a < StartBoard.size(); a++)
							{
								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject = true;
								}
							}

							if (!foundObject)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = true;
							}

							if (StartBoard[i]->catchOption == Pieces::CatchOptions::allaround)
							{
								if ((abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves && location[0] == newlocation[0]) ||
									(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && location[1] == newlocation[1]) ||
									(abs(location[0] - newlocation[0]) <= StartBoard[i]->maxMoves && newlocation[0] - location[0] != 0 && newlocation[1] - location[1] != 0 && (abs((newlocation[0] - '0') - (location[0] - '0')) == abs((newlocation[1] - '0') - (location[1] - '0'))) && abs(location[1] - newlocation[1]) <= StartBoard[i]->maxMoves))
								{
									for (size_t a = 0; a < StartBoard.size(); a++)
									{
										if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
										{
											StartBoard[i]->x = newlocation[0];
											StartBoard[i]->y = newlocation[1] - '0';

											StartBoard[a]->x = 'k';
											StartBoard[a]->y = 1;
											StartBoard[a]->pieceName = "dead";
											playerturn = true;
										}
									}
								}
							}
						}
					}

					/////////// -------------- HORSE MOVEMENT -------------- \\\\\\\\\\\\\\\\\

					if (StartBoard[i]->moveOption == Pieces::MoveOptions::weirdhorsemove && StartBoard[i]->pieceName == "Horse")
					{
						if ((abs(location[1] - newlocation[1]) == StartBoard[i]->maxMoves && abs(location[0] - newlocation[0]) == 1) ||
							(abs(location[0] - newlocation[0]) == StartBoard[i]->maxMoves && abs(location[1] - newlocation[1]) == 1))
						{
							bool foundObject = false;

							for (size_t a = 0; a < StartBoard.size(); a++)
							{

								if ((StartBoard[i]->pieceType == StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0') ||
									(StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0'))
								{
									foundObject = true;

								}
							}

							if (!foundObject)
							{
								StartBoard[i]->x = newlocation[0];
								StartBoard[i]->y = newlocation[1] - '0';
								playerturn = false;
							}
							if (StartBoard[i]->catchOption == Pieces::CatchOptions::weirdhorsecatch)
							{
								for (size_t a = 0; a < StartBoard.size(); a++)
								{
									if (StartBoard[i]->pieceType != StartBoard[a]->pieceType && StartBoard[a]->x == newlocation[0] && StartBoard[a]->y == newlocation[1] - '0')
									{
										StartBoard[i]->x = newlocation[0];
										StartBoard[i]->y = newlocation[1] - '0';

										StartBoard[a]->x = 'k';
										StartBoard[a]->y = 1;
										StartBoard[a]->pieceName = "dead";
										playerturn = false;
									}
								}
							}
						}
					}

				}
			}
		}
		newboard->generateBoard(StartBoard);
	}
}


Game::~Game() //deconstructor
{
	delete newboard;   // dynamic memory removing (delete)
	newboard = nullptr;  // useful usage of nullptr

	delete newstartselect;
	newstartselect = nullptr;

	for (size_t i = 0; i < StartBoard.size(); i++)
	{
		delete StartBoard[i];
		StartBoard[i] = nullptr;

	}
	StartBoard.clear();
}

string Game::getbanner(ifstream &file)
{
	string lines = "";
	if (file) {
		while (file.good()) {
			string tempLine;
			getline(file, tempLine);
			tempLine += "\n";
			lines += tempLine;
		}
		return lines;
	}
	else {
		return "Error: File does not exist.";
	}
}