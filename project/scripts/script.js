for (let i = 0; i < 7; i++) {
    let emojiId = 'emoji' + i;
    let emojiElement = document.getElementById(emojiId);

    if (emojiElement) {
      emojiElement.addEventListener('click', redirect.bind(null, emojiId, emojiElement.innerText));
    }
  }

  let selectedEmoji;


  function redirect(emojiNumber, emojiValue) {
    console.log(emojiNumber);
    selectedEmoji = emojiValue;

    var headerTextElement = document.getElementById('greeting');
    var dataTableElement = document.getElementById('table');
    var textInputElement = document.getElementById('textInput');


    // Update header text
    headerTextElement.innerText = "What's top of mind for you?";

    // Hide the table
    dataTableElement.style.display = 'none';

    // Display the text input
    textInputElement.style.display = 'block';
  }

  let settingElement = document.getElementById('settings');

  if (settingElement) {
    settingElement.addEventListener('click', settingsPage);
  }
  function settingsPage() {
    window.open("options.html", "_blank");
  }


  let inputElement = document.getElementById('button');
  let userInputElement = document.getElementById('userInput');
  if (inputElement) {
    inputElement.addEventListener('click', second_redirect.bind(null, userInputElement))
  }


  let selectedInput;

  function second_redirect(input) {

    console.log(input.value);
    selectedInput = input.value;


    var textInputElement = document.getElementById('userInput');
    var user_emoji = document.getElementById('emoji_of_the_day');
    var headerTextElement = document.getElementById('greeting');
    var WordElement = document.getElementById('word_of_the_day');
    var button = document.getElementById('button');



    textInputElement.style.display = 'none';
    button.style.display = 'none';
    user_emoji.style.display = 'block';
    user_emoji.innerText = selectedEmoji + ' ' + selectedInput;
    headerTextElement.innerText = "Your moodprint:";
    WordElement.style.display = 'block';

    // Get the current date
    const currentDate = new Date();

    // Format the date to YYYY-MM-DD
    const formattedDate = currentDate.toISOString().split('T')[0];

    // User input (emoji and word)
    const userInput = {
      emoji: selectedEmoji,
      word: selectedInput,
    };

    // Combine user input with the date
    const newData = {
      date: formattedDate,
      emoji: userInput.emoji,
      word: userInput.word,
    };

    // Get user ID using the Chrome Identity API
    chrome.identity.getProfileUserInfo(function (userInfo) {
      const userId = userInfo.id;

      // Get existing user data
      chrome.storage.sync.get({ users: {} }, function (result) {
        let userMap = result.users;

        // Check if user data exists
        if (!userMap[userId]) {
          userMap[userId] = [];
        }

        // Remove first entry
        if (userMap[userId].length === 7) {
          userMap[userId].shift();
        }

        // Add the new data
        userMap[userId].push(newData);

        // Save the updated user data
        chrome.storage.sync.set({ users: userMap }, function () {
          console.log('Data saved for user:', userId);
          console.log('Updated user data:', userMap);
        });
      });
    });
  }
