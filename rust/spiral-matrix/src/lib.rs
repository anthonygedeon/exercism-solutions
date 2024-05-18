#[derive(Clone, Copy)]
enum Direction {
    Right,
    Left,
    Up,
    Down,
}

pub fn spiral_matrix(size: u32) -> Vec<Vec<u32>> {
    let mut spiral = Vec::new();

    if size == 0 {
        return spiral;
    }

    for _i in 0..size {
        let new_vec = vec![0; size as usize];
        spiral.push(new_vec);
    }

    let directions = [
        Direction::Right,
        Direction::Down,
        Direction::Left,
        Direction::Up,
    ];

    for d in directions.into_iter().cycle() {
        match d {
            Direction::Right => break,
            Direction::Down => break,
            Direction::Left => break,
            Direction::Up => break,
        }
    }
    println!("{:#?}", spiral);
    spiral
}
