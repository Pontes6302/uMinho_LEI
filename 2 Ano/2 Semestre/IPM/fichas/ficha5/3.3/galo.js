let board = [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]
]

let player = true; // true = X, false = O

let gameStatus;

let ended = false;

document.addEventListener("DOMContentLoaded", () => {
    gameStatus = document.getElementById("game-status");
    gameStatus.textContent = "Jogador X";
    const board = document.getElementById("board");

    const resetButton = document.getElementById("reset");
    resetButton.addEventListener("click", (event) => resetClickHandler(event));

    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            const slot = document.createElement("div");
            slot.className = "slot";
            slot.addEventListener("click", (event) => slotClickHandler(event, i, j));

            board.appendChild(slot);
        }
    }
})

function slotClickHandler(event, i, j) {
    if (board[i][j] !== 0) {
        alert("Casa já ocupada!");
        return;
    }

    if (ended) {
        alert("O jogo já terminou! Clique em reset para jogar novamente.");
        return;
    }

    board[i][j] = player ? 1 : -1;
    event.target.textContent = player ? "X" : "O";
    player = !player;
    gameStatus.textContent = `Jogador ${player ? "X" : "O"}`;

    checkWin();
}

function resetClickHandler(event) {
    board = [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0]
    ];
    const slots = document.getElementsByClassName("slot");
    for (let slot of slots) {
        slot.textContent = "";
    }
    player = true;
    gameStatus.textContent = "Jogador X";
    ended = false;
}

function checkWin(){
    // Check rows and columns
    for (let i = 0; i < 3; i++) {
        let rowSum = board[i][0] + board[i][1] + board[i][2];
        let colSum = board[0][i] + board[1][i] + board[2][i];
        if (rowSum === 3 || rowSum === -3) {
            endGame(board[i][0] > 0 ? "X" : "O");
            return;
        }
        if (colSum === 3 || colSum === -3) {
            endGame(board[0][i] > 0 ? "X" : "O");
            return;
        }
    }

    // Check diagonals
    let diag1Sum = board[0][0] + board[1][1] + board[2][2];
    let diag2Sum = board[0][2] + board[1][1] + board[2][0];
    if (diag1Sum === 3 || diag1Sum === -3) {
        endGame(board[0][0] > 0 ? "X" : "O");
        return;
    }
    if (diag2Sum === 3 || diag2Sum === -3) {
        endGame(board[0][2] > 0 ? "X" : "O");
        return;
    }

    // Check for draw
    if (board.flat().every(cell => cell !== 0)) {
        endGame("Empate");
    }
}

function endGame(winner) {
    ended = true;
    if (winner === "Empate") {
        gameStatus.textContent = "Empate!";
    } else {
        gameStatus.textContent = `Jogador ${winner} venceu!`;
    }
}