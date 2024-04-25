#!/usr/bin/node
const movieId = process.argv[2];

request(`https://swapi-api.hbtn.io/api/films/${movieId}`, (err, res, body) => {
    if (!err) {
        const characters = JSON.parse(body).characters;
        recursionRequestPrint(characters, 0);
    }
});

function recursionRequestPrint(url, index) {
    request(url[index], (err, res, body) => {
        if (!err) {
            console.log(JSON.parse(body).name);
            if (index + 1 < url.length) recursionRequestPrint(url, ++index);
        }
    });
}