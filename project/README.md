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
1) Permissions define what resources or functionalities the extension can access. In this case, it needs access to storage, identity, tabs, and active tabs for its intended functionality.

2) Action pecifies the default popup (hello.html) that appears when the extension icon is clicked. Also, sets the default icon for the extension.

Script.js defines functionality of the extension and its history page.
Options.js define interaction with the Chrome Storage API. In this version of extension logs are stored for the last 7 entries.
CSS files: history.css and style.css define style for the extension and the history page.
Hello.html and options.html build structure for the defaul popup and history page. Each file contains a respective js script.
