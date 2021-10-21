import os
import sys
from github import Github
from git import Repo

from helper_classes import MissingRepoNameException

ACCESS_TOKEN = os.environ['GITHUB_ACCESS_TOKEN']
PROJECT_FOLDER = 'D:\\Code'

g = Github(ACCESS_TOKEN)

if len(sys.argv) < 2:
    raise MissingRepoNameException()

# create a github repo with the given name
user = g.get_user()
project_name = sys.argv[1]

try:
    repo = user.create_repo(project_name)
except:
    print('Repo creation failed.')
    quit()
else:
    print(f"Repo with name {project_name} created!")

# make a README.md
repo.create_file('README.md', "initial commit", f"# {project_name.title()}")

# cd to right folder
os.chdir(PROJECT_FOLDER)

# create a new folder
os.system(f'mkdir {project_name}')

# cd to project folder
os.chdir(project_name)

# clone the repo
Repo.clone_from(repo.git_url, './')

# open vscode
os.system('code .')
