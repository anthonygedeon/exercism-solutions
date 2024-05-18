pub fn production_rate_per_hour(speed: u8) -> f64 {
    // match is an expression that gets evaluted to a value
    221.0 * (speed as f64) * match speed {
        0..=4 => 1.0,
        5..=8 => 0.90,
        9..=u8::MAX => 0.77,
    }
}

pub fn working_items_per_minute(speed: u8) -> u32 {
    let cars_in_an_hour = production_rate_per_hour(speed);
    (cars_in_an_hour/60.0) as u32
}
