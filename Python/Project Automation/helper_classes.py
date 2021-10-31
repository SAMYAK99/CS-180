class MissingRepoNameException(Exception):
    def __init__(self, message='Repository/ Project name is missing.'):
        self.message = message
        super().__init__(self.message)
