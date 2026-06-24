<script>
import { Jogo } from "../models/jogo";
import { ResultadoJogada } from "../models/resultadoJogada";
import { ResultadoJogo } from "../models/resultadoJogo";
import Button from "./Button.vue";

export default {
  components: {
    Button
  },
  emits: ['estado-jogo'],
  data() {
    return {
      jogo: new Jogo(),
      numColunas: 7,
      numLinhas: 6
    }
  },
  methods: {
    jogar(coluna) {
      const resultado = this.jogo.jogar(coluna);

      if (resultado === ResultadoJogada.ERRO_COLUNACHEIA) {
        alert("Coluna cheia. Escolha outra coluna.");
      }
      else if (resultado === ResultadoJogada.ERRO_COLUNAINVALIDA) {
        alert("Coluna inválida.");
      }
      else if (resultado === ResultadoJogada.ERRO_JOGOTERMINADO) {
        alert("Jogo já terminado. Reinicie para jogar novamente.");
      }
      else if (resultado === ResultadoJogada.TERMINOU){
        this.emitirEstadoJogo();
      }
      else if (resultado === ResultadoJogada.SUCESSO){
        this.emitirEstadoJogo();
      }
    },
    reset() {
      this.jogo.reset();
      this.emitirEstadoJogo();
      alert(`Novo jogo: começa o jogador ${this.nomeJogador(this.jogo.jogadorAJogar)}.`);
    },
    emitirEstadoJogo() {
      this.$emit('estado-jogo', {
        jogadorAJogar: this.jogo.jogadorAJogar,
        vencedor: this.jogo.vencedor
      });
    },
    nomeJogador(jogador) {
      return jogador ? 'vermelho' : 'amarelo';
    },
    aplicarVermelho(coluna, linha) {
      return this.jogo.getCelula(coluna, linha) === true ? "red" : "";
    },
    aplicarAmarelo(coluna, linha) {
      return this.jogo.getCelula(coluna, linha) === false ? "yellow" : "";
    },
  },
  mounted() {
    this.emitirEstadoJogo();
  }
}
</script>

<template>
  <div class="tabuleiro">
    <div v-for="c in numColunas" :key="c" class="coluna" @click="jogar(c - 1)">
      <div v-for="l in numLinhas" :key="l"
        class="celula"
        :class="[aplicarVermelho(c - 1, l - 1), aplicarAmarelo(c - 1, l - 1)]"
        >
      </div>
    </div>
  </div>
  <div class="button-container">
    <Button @click="reset()">Reset</Button>
  </div>
</template>

<style scoped>
.tabuleiro {
  display: flex;
  width: 40%;
  margin: 20px auto auto;
  background-color: #4357A0;
  padding: 10px;
  border-radius: 10px;
}

.coluna {
  display: flex;
  flex-direction: column;
  flex-grow: 1;
}

.celula {
  border-radius: 100%;
  background-color: #001773;
  max-height: 100%;
  max-width: 100%;
  aspect-ratio: 1;
  margin: 4px;
}

.yellow {
  background-color: var(--color-yellow);
}

.red {
  background-color: var(--color-red);
}

.button-container {
  display: flex;
  justify-content: center;
  margin-top: 40px;
}
</style>