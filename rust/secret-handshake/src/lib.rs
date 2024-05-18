// TODO: Is there a better way to write this code
pub fn actions(n: u8) -> Vec<&'static str> {
    let mut handshakes = vec![];

    if (n & 0x1) != 0 {
        handshakes.push("wink");
    }

    if (n & 0x2) != 0 {
        handshakes.push("double blink");
    }

    if (n & 0x4) != 0 {
        handshakes.push("close your eyes");
    }

    if (n & 0x8) != 0 {
        handshakes.push("jump");
    }

    if n & 0x10 != 0 {
        // Why do I not run into a ownership problem? `into_iter` consumes handshakes
        handshakes.into_iter().rev().collect::<Vec<_>>()
    } else {
        // I can still use handshakes here. Is it because of the if else block?
        handshakes
    }
}
