// The code below is a stub. Just enough to satisfy the compiler.
// In order to pass the tests you can add-to or change any of this code.

#[derive(Debug)]
pub struct Duration {
    day: f64,
}

impl From<u64> for Duration {
    // convert seconds to days
    fn from(s: u64) -> Self {
        Duration {
            day: ((s as f64 / 60.0) / 60.0) / 24.0,
        }
    }
}

pub trait Planet {
    fn years_during(d: &Duration) -> f64;
}

macro_rules! planet {
    ($planet:ident , $period:expr) => {
        pub struct $planet;
        impl Planet for $planet {
            fn years_during(d: &Duration) -> f64 {
                d.day / $period
            }
        }
    };
}

const MERCURY_ORBITAL: f64 = 87.97;
const VENUS_ORBITAL: f64 = 224.7;
const EARTH_ORBITAL: f64 = 365.249;
const MARS_ORBITAL: f64 = 686.98;
const JUPITER_ORBITAL: f64 = 4332.59;
const SATURN_ORBITAL: f64 = 10_756.0;
const URANUS_ORBITAL: f64 = 30_687.0;
const NEPTUNE_ORBITAL: f64 = 60_190.0;

planet!(Mercury, MERCURY_ORBITAL);
planet!(Venus, VENUS_ORBITAL);
planet!(Earth, EARTH_ORBITAL);
planet!(Mars, MARS_ORBITAL);
planet!(Jupiter, JUPITER_ORBITAL);
planet!(Saturn, SATURN_ORBITAL);
planet!(Uranus, URANUS_ORBITAL);
planet!(Neptune, NEPTUNE_ORBITAL);
