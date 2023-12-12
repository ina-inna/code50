function main() {
    console.log('Displaying history for user:');
    chrome.identity.getProfileUserInfo(function (userInfo) {
        const userId = userInfo.id;
        // Get user-specific data
        chrome.storage.sync.get({ users: {} }, function (result) {
            const userMap = result.users;
            const userData = userMap[userId] || [];

            // Get the container element
            const dataContainer = document.getElementById("data-container");

            document.addEventListener("DOMContentLoaded", function () {

                // Check if the container element is found
                if (dataContainer) {
                    // Clear existing content in the container
                    dataContainer.innerHTML = "";

                    const newChildElement = document.createElement("p");
                    newChildElement.textContent = "This is a new paragraph.";
                    dataContainer.appendChild(newChildElement);

                } else {
                    console.error("Container not found");
                }
            });

            // Iterate through the user-specific data and create HTML elements
            userData.forEach(entry => {
                // Create a new div element
                const entryDiv = document.createElement("div");

                // Set the content of the div
                entryDiv.innerHTML = `
                <p>Date: ${entry.date}</p>
                <p>Emoji: ${entry.emoji}</p>
                <p>Word: ${entry.word}</p>
                <hr>
            `;

                // Append the div to the container
                dataContainer.appendChild(entryDiv);
                console.log('User-specific history for the last 7 days:', userData);
            });
        });
    });

}

main();
