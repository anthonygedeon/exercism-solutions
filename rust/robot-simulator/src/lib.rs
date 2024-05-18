// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(PartialEq, Eq, Debug)]
pub enum Direction {
    North,
    East,
    South,
    West,
}

pub struct Robot {
    x: i32,
    y: i32,
    d: Direction,
}

impl Robot {
    pub fn new(x: i32, y: i32, d: Direction) -> Self {
        Self { x, y, d }
    }

    #[must_use]
    pub fn turn_right(self) -> Self {
        match self.d {
            Direction::North => Self::new(self.x, self.y, Direction::East),
            Direction::East => Self::new(self.x, self.y, Direction::South),
            Direction::South => Self::new(self.x, self.y, Direction::West),
            Direction::West => Self::new(self.x, self.y, Direction::North),
        }
    }

    #[must_use]
    pub fn turn_left(self) -> Self {
        match self.d {
            Direction::North => Self::new(self.x, self.y, Direction::West),
            Direction::East => Self::new(self.x, self.y, Direction::North),
            Direction::South => Self::new(self.x, self.y, Direction::East),
            Direction::West => Self::new(self.x, self.y, Direction::South),
        }
    }

    #[must_use]
    pub fn advance(self) -> Self {
        match self.d {
            Direction::North => Self::new(0, 1, self.d),
            Direction::East => Self::new(1, 0, self.d),
            Direction::South => Self::new(0, -1, self.d),
            Direction::West => Self::new(-1, 0, self.d),
        }
    }

    #[must_use]
    pub fn instructions(self, instructions: &str) -> Self {
        unimplemented!()
    }

    pub fn position(&self) -> (i32, i32) {
        match self.d {
            Direction::North => (self.x, self.y),
            Direction::South => (self.x, self.y),
            Direction::West => (self.x, self.y),
            Direction::East => (self.x, self.y),
        }
    }

    pub fn direction(&self) -> &Direction {
        &self.d
    }
}
