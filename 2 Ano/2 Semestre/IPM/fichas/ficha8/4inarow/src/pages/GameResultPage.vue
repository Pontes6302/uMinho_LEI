<script>
import { Game } from "../models/game.js";

export default {
  props: ['id'],
  data() {
    return {
      game: new Game()
    };
  },
  methods: {
    async getGame() {
      try {
        const response = await fetch(`http://localhost:3000/games/${this.id}`);

        if (!response.ok) {
          throw new Error('Something went wrong');
        }

        const data = await response.json();

        if (data.game) {
          this.game.board = data.game.board;
          this.game.player = data.game.player;
          this.game.winner = data.game.winner;
          this.game.isOver = data.game.isOver;
          return;
        }

        this.game.board = data.board;
        this.game.player = data.player;
        this.game.winner = data.winner;
        this.game.isOver = true;
      } catch (error) {
        console.log(error);
      }
    }
  },
  created() {
    this.getGame();
  }
}
</script>

<template>
  <game-board :game="game"></game-board>
</template>