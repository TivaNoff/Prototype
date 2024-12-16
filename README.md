Припустімо, у нас є клас Shape – це базовий клас для різних геометричних фігур (Circle, Square). Кожна фігура може мати унікальні властивості (наприклад, радіус для кола, довжину сторони для квадрата). Використовуючи патерн «Прототип», ми визначимо в базовому класі метод clone(), який повертатиме копію поточного об’єкта. Похідні класи (Circle, Square) реалізовуватимуть цей метод, повертаючи власну копію. Таким чином, створюючи нові об’єкти фігур шляхом клонування вже існуючих, ми можемо уникнути витрат на повторну ініціалізацію складних властивостей.
