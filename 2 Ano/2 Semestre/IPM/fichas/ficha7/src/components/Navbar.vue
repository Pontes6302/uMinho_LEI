<script>
import { ResultadoJogo } from "../models/resultadoJogo";

export default {
  props: ['jogadorAJogar', 'vencedor'],
  computed: {
    mensagem() {
      if (this.vencedor === null) {
        return `Jogador a jogar: ${this.jogadorAJogar ? 'Vermelho' : 'Amarelo'}`;
      }

      if (this.vencedor === ResultadoJogo.VERMELHO) {
        return 'Resultado Final: Venceu o jogador Vermelho';
      }

      if (this.vencedor === ResultadoJogo.AMARELO) {
        return 'Resultado Final: Venceu o jogador Amarelo';
      }

      return 'Resultado Final: Empate';
    }
  }
}
</script>

<template>
  <div class="button">{{ mensagem }}</div>
</template>

<style scoped>
.button {
  border: 1px solid black;
  border-radius: 5px;
  text-align: center;
  padding: 10px;
  font-weight: 600;
}
</style>