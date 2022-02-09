// TODO: Refactor this mess
pub fn verse(n: u32) -> String {
    let mut verses = vec![];
    if n == 0 {
        let v = format!("No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bottles of beer on the wall.\n");
        verses.push(v);
        let song = verses.join("").to_string();
        return song; 
    }
    let pural: String; 
    let main_verse: String;
    
    if n > 2 {
        pural = String::from("bottles");
    } else {
        pural = String::from("bottle");
    }

    if n == 1 {
        main_verse = format!("{} bottle of beer on the wall, {} bottle of beer.\nTake it down and pass it around, no more bottles of beer on the wall.\n", n , n);
    } else {
        let overflow_n = match n.checked_sub(1) {
            None => 0, 
            Some(value) => value
        };
        main_verse = format!("{} bottles of beer on the wall, {} bottles of beer.\nTake one down and pass it around, {} {} of beer on the wall.\n", n , n, overflow_n, pural);
    }         

    verses.push(main_verse);
    verses.join("").to_string()
}

// TODO: Refactor this mess
pub fn sing(start: u32, end: u32) -> String {
    let mut song = String::new();
    for i in (end..=start).rev() {
        println!("{}", i);
        let verse = verse(i) ;
        song.push_str(&format!("\n{}", &verse));
    }
    song.trim_start().to_string()
}
