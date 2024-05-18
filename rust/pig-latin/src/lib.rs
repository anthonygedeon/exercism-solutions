const VOWELS: &[char; 5] = &['a', 'e', 'i', 'o', 'u'];

mod pig_latin {
    pub struct PigLatin<'a>{
        word: &'a str
    }

    enum Syllable {
        Vowel,
        Consonants(char)
    }

    impl From<char> for Syllable {
        fn from(item: char) -> Self {
            match item {
                'a' | 'e' | 'i' | 'o' | 'u' => Syllable::Vowel, 
                _ => Syllable::Consonants(item)
            }
        }
    }

    impl<'a> PigLatin<'a> {
        pub fn new(word: &'a str) -> Self {
            PigLatin {
                word, 
            }
        }

        /// Translate the characters to fit the rules of pig latin.
        ///
        /// # Examples
        ///
        /// ``` 
        /// let pig_lang = PigLatin::new("Hello, World!").encode();
        /// assert_eq("elloHay, orldWay!", pig_lang);
        /// ```
        pub fn encode(&self) -> Self {
            todo!("Handle 'qu' case");
            todo!("Handle consonants cluster");
            todo!("Handle 'yt' 'xr' being vowels due to phonentics");

            if let Some(first_letter) = self.word.chars().nth(0) {
                let syllable = Syllable::from(first_letter);

                match syllable {
                    Syllable::Vowel => todo!("issue understanding lifetimes, come back later"),
                    Syllable::Consonants(c) => todo!("issue understanding lifetimes, come back later"),
                }

            }         

            PigLatin { word: "" }
        }

        /// Take the encoded message and translate it back to English.
        ///
        /// # Examples
        ///
        /// ``` 
        /// let pig_lang = PigLatin::new("Hello, World!").encode().decode();
        /// assert_eq("Hello, World!", pig_lang);
        /// ```
        pub fn decode(&self) -> Self {
            unimplemented!()
        }
    }

}

fn to_pig_latin(word: &mut String) -> String {
    let mut encoded = String::new();    

    let mut is_consonant_cluster = false;

    // Handle vowel case
    if word.starts_with(VOWELS) || word.starts_with("xr") || word.starts_with("yt") {
        encoded.push_str(&format!("{}ay", word));
    }

    // Handle consonants case
    let mut consonant: Option<char> = None;
    while !word.starts_with(VOWELS) && !word.starts_with("xr") && !word.starts_with("yt") {
        is_consonant_cluster = true;
        consonant = Some(word.remove(0));
        encoded.push(consonant.unwrap_or(' '));
    }
    
    // edge case
    // if starts with 'q' and is followed with 'u' then 
    //      remove those letters from the str
    if let Some(ch) = consonant {
        if ch == 'q' && word.starts_with('u') {
            let consonant = word.remove(0);
            encoded.push(consonant);
        }
    }

    if is_consonant_cluster {
        encoded = format!("{}{}ay", word, encoded);
    }

    encoded
}

use pig_latin::PigLatin;

pub fn translate(input: &str) -> String {
    
    // TODO: Make it better
    PigLatin::new(input).encode();

    input
        .to_lowercase()
        .split_whitespace()
        .map(|word| to_pig_latin(&mut word.to_string()))
        .collect::<Vec<String>>()
        .join(" ")
}
