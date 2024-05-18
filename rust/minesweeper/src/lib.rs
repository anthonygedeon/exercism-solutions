#![feature(is_some_and)]

// Brother in christ... Please fix this code NOW
pub fn annotate(minefield: &[&str]) -> Vec<String> {
    if minefield.is_empty() {
        return vec![];
    }

    let mut board: Vec<Vec<char>> = vec![vec![]];
    for (i, row) in minefield.iter().enumerate() {
        if i != 0 {
            board.push(vec![]);
        }
        for cell in row.chars() {
            board[i].push(cell);
        }
    }

    for (i, row) in board.clone().iter().enumerate() {
        for (j, &col) in row.iter().enumerate() {
            let mut adjacent_mines: u8 = 0;

            // check Diagonal Left
            if i.checked_sub(1).is_some() && j.checked_sub(1).is_some() {
                if col.is_ascii_whitespace() {
                    if board
                        .get(i - 1)
                        .unwrap()
                        .get(j - 1)
                        .is_some_and(|c| *c == '*')
                    {
                        adjacent_mines += 1;
                        board[i][j] = (adjacent_mines + b'0') as char;
                    }
                }
            }

            // check Diagonal Right
            if i.checked_sub(1).is_some() {
                if col.is_ascii_whitespace() {
                    if board
                        .get(i - 1)
                        .unwrap()
                        .get(j + 1)
                        .is_some_and(|c| *c == '*')
                    {
                        adjacent_mines += 1;
                        board[i][j] = (adjacent_mines + b'0') as char;
                    }
                }
            }

            // check Diagonal Bottom Left
            if let Some(_) = board.get(i + 1) {
                if col.is_ascii_whitespace() {
                    if j.checked_sub(1).is_some() {
                        if board
                            .get(i + 1)
                            .unwrap()
                            .get(j - 1)
                            .is_some_and(|c| *c == '*')
                        {
                            adjacent_mines += 1;
                            board[i][j] = (adjacent_mines + b'0') as char;
                        }
                    }
                }
            }

            // check Diagonal Bottom Right
            if let Some(_) = board.get(i + 1) {
                if col.is_ascii_whitespace() {
                    if board
                        .get(i + 1)
                        .unwrap()
                        .get(j + 1)
                        .is_some_and(|c| *c == '*')
                    {
                        adjacent_mines += 1;
                        board[i][j] = (adjacent_mines + b'0') as char;
                    }
                }
            }

            // check up
            if col.is_ascii_whitespace() {
                if let Some(vertical_board) = board.get(i + 1) {
                    if vertical_board.get(j).is_some_and(|c| *c == '*') {
                        adjacent_mines += 1;
                        board[i][j] = (adjacent_mines + b'0') as char;
                    }
                }
            }

            // check down
            if col.is_ascii_whitespace() {
                if i.checked_sub(1).is_some() {
                    if board.get(i - 1).unwrap().get(j).is_some_and(|c| *c == '*') {
                        adjacent_mines += 1;
                        board[i][j] = (adjacent_mines + b'0') as char;
                    }
                }
            }

            // check right
            if col.is_ascii_whitespace() {
                if board.get(i).unwrap().get(j + 1).is_some_and(|c| *c == '*') {
                    adjacent_mines += 1;
                    board[i][j] = (adjacent_mines + b'0') as char;
                }
            }

            // check left
            if j.checked_sub(1).is_some() {
                if col.is_ascii_whitespace() {
                    if board.get(i).unwrap().get(j - 1).is_some_and(|c| *c == '*') {
                        adjacent_mines += 1;
                        board[i][j] = (adjacent_mines + b'0') as char;
                    }
                }
            }
        }
    }

    let mut board_v = vec![];

    for row in board {
        let s = String::from_iter(row);
        board_v.push(s);
    }

    board_v
}
