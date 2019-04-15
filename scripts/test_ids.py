from webids import ids

input_stream = """asklgjd;fgjsdfg***subprocess.call***fasd.fsdlgkjsdfgsdfg
flsk ***/bin/sh*** asdjhglsdfkgh;klasdfjkdfv asdlfksd;flkjgsd;flkgjsd;fl 
 ***something.py***"""

platform = "cuda"

print(ids(platform, input_stream))

