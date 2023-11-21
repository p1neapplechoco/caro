v1.0 (31/10/23)
- revamped menu.
- added logo.
- fixed:
	+ Console commands.
	+ Window.

v1.1 (1/11/23)
- added a board (would be later revamped).
- added the pixelColoring function (don't know if i would use it later).

v1.5 (BIG UPDATE) (1/11/23 <- golden day)
- added undo function.
- rewrite some codes (input, drawBoard)
- fixed:
	+ cursor going out of bound.
	+ overwriting the marks.

v2.0 (3/11/23)
- added win/draw condition.
- added a temporary winner screen.
- rewrite the checkTurn() function.
fixed:
	+ the bug where you undo the board and cannot mark the empty undo-ed board.
	+ checking win not really working.

v2.0.1 (3/11/23)
- minor bugs fixed. (undo-ing counts win)

v2.1 (9/11/23)
- added saving feature (doesn't have loading the game tho).
- made header file actually useful.
- fixed resetData() error where you cannot have a empty board when starting the game.

v2.2 (10/11/23)
- added loading feature.
- minor fixes:
	+ always uses 'X' as the starting marker.

v2.3
- fixed saving.

v2.5 (22/11/23)
- optimized code.
- fixed board drawing flickering.

v2.5.1 (23/11/23)
- fixed checkDraw doesn't work when loading a save files.
- added color for marks.
- optimized code.
