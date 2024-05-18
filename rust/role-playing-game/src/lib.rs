pub struct Player {
    pub health: u32,
    pub mana: Option<u32>,
    pub level: u32,
}

impl Player {
    pub fn new(level: u32) -> Self {
        Self { 
            health: 100, 
            mana: if level < 10 { None } else { Some(100) }, 
            level 
        }
    }

    pub fn revive(&self) -> Option<Player> {
        match self.health {
            0 => Some(Self::new(self.level)), 
            _ => None 
        }
    }

    pub fn cast_spell(&mut self, mana_cost: u32) -> u32 {
        match self.mana {
            Some(v) => {
                if v >= mana_cost {
                    self.mana = Some(v - mana_cost);
                    mana_cost * 2
                } else {
                    0
                }
            }
            None => {
                // pick one of the smaller value 
                // if it picks self.health then the health field will be 0
                // else health will be lowered by the mana_cost
                self.health -= std::cmp::min(self.health, mana_cost);
                0
            }
        }
    }
}
