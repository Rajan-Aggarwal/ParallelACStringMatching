import json
import requests

def ids(platform, input_stream):
    assert (platform in ["cuda", "mpi"]), "Invalid platform!"
    data = [{'platform': platform, 'input': input_stream}]
    json_obj = json.dumps(data)
    res = requests.post("http://127.0.0.1:5000/pasm/", json=json_obj).json()

    return res['matches']