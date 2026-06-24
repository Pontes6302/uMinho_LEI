const app = Vue.createApp({
  //vairáveis-estados
  data() {
    return {
      todos: [
        'Learn a new course',
        'Read a book',
        'Go to the gym',
        'Go shopping'
      ],
      today : new Date().toLocaleDateString('pt-PT'),
      enteredTodo: ''
    }
  },
  //funções-métodos para manipular os dados
  methods: {
    submitTodo() {
      const todo = this.enteredTodo.trim();
      //verificar se é vazio
      if (todo === '') {
        alert('Please enter a todo!');
        return;
      }

      //verificar se já existe
      const exists = this.todos.some(t => t.toLowerCase() === this.enteredTodo.toLowerCase());
      if (exists) {
        alert('This todo already exists!');
        return;
      }

      //adicionar a nova tarefa à lista
      this.todos.push(this.enteredTodo);

      //limpar o campo de entrada
      this.enteredTodo = '';
    },
    deleteTodo(index) {
      this.todos.splice(index, 1);
    }
  },
  //valores computados para processar os dados, cache
  computed: {
    isDisabled(){
      return this.enteredTodo.trim() === '';
    }
  }
});

app.mount('#app');