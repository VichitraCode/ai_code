import nltk
from nltk.chat.util import Chat, reflections

reflections = {
  "i am"       : "you are",
  "i was"      : "you were",
  "i"          : "you",
  "i'm"        : "you are",
  "i'd"        : "you would",
  "i've"       : "you have"
}

pairs = [
    [
        r"my name is (.*)",
        ["Hello %1, How are you today ?",]
    ],
    [
        r"hi|hey|hello",
        ["Hello", "Hey there",]
    ], 
    [
        r"what is your name ?",
        ["I am a bot created by Analytics Vidhya. you can call me crazy!",]
    ],
    [
        r"how are you ?",
        ["I'm doing good \nHow about You ?",]
    ]
]

def chat():
    print("Hi! I am a chatbot created by Analytics Vidhya for your service")
    chat = Chat(pairs, reflections)
    chat.converse()
#initiate the conversation
if __name__ == "__main__":
    chat()