# YOUR PROJECT TITLE
#### Video Demo:  https://youtu.be/66jbJBrjfJo
#### Description:
Moodprint is a chrome extension aimed at promoting mental well-being by fostering self-awareness.  It's designed to help users log their mood and thoughts easily.
Key features:
User-Friendly Interface: The extension has a simple yet intuitive interface for logging your mood and thoughts.
Time Stamping: Every entry is automatically time-stamped, allowing users to track patterns and trends over time.
Chrome Storage API: I implemented the Chrome Storage API to ensure that user data is securely stored across sessions.

UX solution: I chose gradient colors to reflect a floating and changing nature of our emotional state. Blue and purple are perceived soothing and tend to relax people so that they could open up more.


The backbone of the extension is built with JavaScript, which powers both the content and history scripts.


Manifest.json file serves as a blueprint for a Chrome extension. It outlines the extension's metadata, settings, and permissions, providing the necessary information for both users and the browser to understand how the extension should function and behave.
Key fields:
1) Name: This is what users will see as the name of your extension in the Chrome Web Store and their browser. It provides clarity and branding.
2) Description informs users about the purpose and functionality of your extension. It's essential for users to understand what your extension does.
3) Versioning is crucial for managing updates. It helps users and developers track changes and ensures compatibility.
4) Manifest version 3 is the latest version that introduces improvements and changes to enhance extension security and performance.
6) Permissions define what resources or functionalities the extension can access. In this case, it needs access to storage, identity, tabs, and active tabs for its intended functionality.

7) Action pecifies the default popup (hello.html) that appears when the extension icon is clicked. Also, sets the default icon for the extension.
8) Options page points to the page where users can customize settings and preferences for the extension. It's essential for user interaction and personalization.

Script.js defines functionality of the extension and its history page.
Emoji Selection:

The code uses a loop to iterate over seven elements (presumably emoji elements) on the page and adds a click event listener to each. When an emoji is clicked, it triggers the redirect function, passing the emoji ID and its inner text.
Redirect Function:

The redirect function is called when an emoji is clicked. It updates the UI by changing the header text, hiding a table, and displaying a text input field.
Settings Page:

It adds an event listener to an element with the ID 'settings.' When this element is clicked, it opens the 'options.html' page in a new tab.
User Input Handling:

It adds an event listener to an element with the ID 'button.' When clicked, it triggers the second_redirect function, passing the user input element.
Second Redirect Function:

The second_redirect function is called when the button is clicked. It retrieves the user input value, updates the UI by displaying an emoji and the user's input, and changes the header text.
Data Storage:

It retrieves the current date, formats it, and creates an object (newData) containing the date, selected emoji, and user input.
It uses the Chrome Identity API to get the user's ID and Chrome Storage API to store user data.
The user data is stored in a map with user IDs as keys and an array of user inputs as values.
If a user already has seven entries, it removes the oldest one before adding the new data.
The updated user data is then saved in Chrome storage.





Options.js define interaction with the Chrome Storage API. In this version of extension logs are stored for the last 7 entries.
Let's break down its functionality:

The main function is the entry point of the script. It logs a message to the console and then uses the Chrome Identity API to retrieve the user's ID.
Data Retrieval:

It retrieves user-specific data from Chrome storage using the Chrome Storage API. The user's data is stored in a map with user IDs as keys, and the extension is looking specifically for the current user's data.
HTML Element Creation:

The script then creates and manipulates HTML elements dynamically. It looks for an HTML element with the ID 'data-container' to serve as the container for displaying user data.
Document Ready Event:

The script listens for the 'DOMContentLoaded' event to ensure the HTML document is fully loaded before attempting to manipulate the DOM.
Container Check and Clearing:

It checks if the container element (data-container) exists. If found, it clears any existing content within the container.
New Child Element:

It creates a new element with the text "This is a new paragraph" and appends it to the container. This seems to be a placeholder or an initial content marker.
User Data Rendering:

It iterates through the user-specific data obtained from Chrome storage and creates HTML elements dynamically for each entry. Each entry is displayed in a div with details such as the date, emoji, and word. A horizontal line (<hr>) separates each entry.
Console Logging:

It logs the user-specific history for the last 7 days to the console.
CSS files: history.css and style.css define style for the extension and the history page.
Hello.html and options.html build structure for the defaul popup and history page. Each file contains a respective js script.
