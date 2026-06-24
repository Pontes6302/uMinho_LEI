import { createRouter, createWebHistory } from 'vue-router';
import GamePage from './pages/GamePage.vue';
import GameResultPage from './pages/GameResultPage.vue';
import StatisticsPage from './pages/StatisticsPage.vue';
import SimulationPage from './pages/SimulationPage.vue';
import NotFoundPage from './pages/NotFoundPage.vue';

const router = createRouter({
  history: createWebHistory(),
  routes: [
    { path: '/game', component: GamePage},
    { path: '/game/:id', component: GameResultPage, props: true },
    { path: '/statistics', component: StatisticsPage},
    { path: '/simulation', component: SimulationPage},
    { path: '/', redirect: '/game' },
    { path: '/:pathMatch(.*)*', component: NotFoundPage }
  ]
});

export default router;