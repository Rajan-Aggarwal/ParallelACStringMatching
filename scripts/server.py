import subprocess
from flask import Flask
from flask import request
import json

app = Flask(__name__)

def match_cuda(input_stream):
    f=open("/path/to/input_stream/", 'w')
    f.write(input_stream)
    f.close()

    matches = subprocess.check_output(["/path/to/binary/"]).decode("utf-8")

    return matches

def match_mpi(input_stream):
    f=open("/path/to/input_stream/", 'w')
    f.write(input_stream)
    f.close()

    matches = subprocess.check_output(["mpirun -n 150 /path/to/binary/"], shell=True).decode("utf-8")

    return matches


@app.route('/pasm/', methods=['POST'])
def string_match():
    data = json.loads(request.get_json())[0]

    matches = ""
    if data['platform'] == "cuda":
        matches = match_cuda(data['input'])
    elif data['platform'] == 'mpi':
        matches = match_mpi(data['input'])
    
    if matches == "":
        matches = "Status: OK.\nNo vulnerabilities detected."
    else:
        matches += "Status: Error! Possible vulnerabilities detected!"

    return json.dumps({'matches': matches})

if __name__ == '__main__':
    app.run()