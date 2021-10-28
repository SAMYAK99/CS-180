import random


class Enemy(object):

    def __init__(self, name="Enemy", hit_points=0, lives=1) -> None:
        self.name = name
        self._hit_points = hit_points
        self._lives = lives

    def take_damage(self, damage):
        remaining_points = self._hit_points - damage
        if remaining_points >= 0:
            self._hit_points = remaining_points
            print(f"I took {damage} points damage and have {self._hit_points} left")
        else:
            self._lives -= 1
            if self._lives > 0:
                print("{0.name} lost a life.".format(self))
            else:
                print("{0.name} is dead.")

    def __str__(self) -> str:
        return "Name: {0.name}, Lives: {0._lives}, Hit points: {0._hit_points}".format(self)


class Troll(Enemy):

    def __init__(self, name, hit_points=0, lives=1) -> None:
        super().__init__(name=name, hit_points=hit_points, lives=lives)


class Vampire(Enemy):

    def __init__(self, name, hit_points=23, lives=3) -> None:
        super().__init__(name=name, hit_points=hit_points, lives=lives)

    def take_damage(self, damage):
        if not self.dodges():
            super().take_damage(damage=damage)

    def dodges(self):
        if random.randint(1, 3) == 3:
            print('***** {0.name} dodges *****'.format(self))
            return True
        else:
            return False


class Player(object):
    def __init__(self, name) -> None:
        self.name = name
        self._lives = 3
        self._level = 1
        self._score = 0
    
    def _get_lives(self):
        return self._lives
    
    def _set_lives(self, lives):
        if lives >= 0:
            self._lives = lives
        else:
            self._lives = 0

    def _get_level(self):
        return self._level

    def _set_level(self, level):
        if level > 0:
            delta = level - self._level
            self._score += delta * 100
            self._level = level
        else:
            print("Level can't be less than 1")

    lives = property(_get_lives, _set_lives)
    level = property(_get_level, _set_level)


    @property
    def score(self):
        return self._score

    @score.setter
    def score(self, score):
        self._score = score

    def __str__(self) -> str:
        return f'Name: {self.name}, Lives: {self.lives}, Level: {self.level}, Score: {self.score}'


if __name__ == '__main__':

    vampire = Vampire("Vald")
    print(vampire)

    vampire.take_damage(18)
    vampire.take_damage(10)
    vampire.take_damage(11)