import UIKit

struct Joke{
    var joke: String
    var punchline: String
}

var setups = [
    "Why did the chicken cross the road?",
    "Why couldn't the bicycle stand up?",
    "Is this pool safe for diving?",
    "Wanna hear a joke about paper?",
    "What did the grape do when he got stepped on?",
    "What do you call a cheese by itself?",
    "What do you call a deer with no eyes?",
    "Don't trust atoms",
    "I knew I shouldn't have seafood",
    "I wouldn't buy anything with velcro",
    "Why did the scarecrow win an award?",
    "'I will call you later'",
    "What do you call somebody with no body and no nose?",
    "What do you call a fake pasta?",
    "Why do crabs never give to charity?"
]
var punchlines = [
    "To get to the other side!",
    "It was two tired!",
    "It deep ends",
    "Nevermind, it's tearable",
    "He let out a little wine",
    "Provolone",
    "No Idea",
    "They make up eveything",
    "I am feeling a little eel",
    "It's a total rip-off",
    "Because he was outstanding in his field",
    "Don't call me later, call me Dad",
    "Nobody knows",
    "An Impasta",
    "Beacause they're shellfish"
]

var jokes = [Joke]()
for i in 0..<setups.count{ jokes.append(Joke(joke: setups[i], punchline: punchlines[i])) }
print(jokes)


