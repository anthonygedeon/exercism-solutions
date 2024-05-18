use rand::Rng;

static mut REGISTRY: Vec<String> = Vec::new();

pub struct Robot {
    name: String,
}

impl Robot {
    pub fn new() -> Self {
        Self::default()
    }

    // convenience function
    fn gen_name() -> String {
        let mut rng = rand::thread_rng();
        let num = rng.gen_range(0..1000);
        let letter_1 = rng.gen_range(b'A'..=b'Z') as char;
        let letter_2 = rng.gen_range(b'A'..=b'Z') as char;
        format!("{letter_1}{letter_2}{num:03}")
    }

    fn gen_unique_name() -> String {
        let mut name = Self::gen_name();
        unsafe {
            while REGISTRY.contains(&name) {
                name = Self::gen_name();
            }
            REGISTRY.push(name.clone());
        }

        name
    }

    pub fn name(&self) -> &str {
        self.name.as_ref()
    }

    pub fn reset_name(&mut self) {
        self.name = Self::gen_name()
    }
}

impl Default for Robot {
    fn default() -> Self {
        Self {
            name: Self::gen_unique_name(),
        }
    }
}
