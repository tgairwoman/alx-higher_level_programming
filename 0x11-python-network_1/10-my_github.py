#!/usr/bin/python3
"""Python script that takes your GitHub credentials
(username and password) and uses the GitHub API to display your id
"""
import requests
import sys

def get_user_id(username, password):
    url = f'https://api.github.com/users/{username}'
    response = requests.get(url, auth=(username, password))
    if response.status_code == 200:
        user_data = response.json()
        user_id = user_data.get('id')
        return user_id
    else:
        print(f"Failed to retrieve user details. Status code: {response.status_code}")
        return None

if __name__ == '__main__':
    username = sys.argv[1]
    password = sys.argv[2]
    user_id = get_user_id(username, password)
    if user_id:
        print(f"User ID: {user_id}")
