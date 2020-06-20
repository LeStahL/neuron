import pyglsl_parser, argparse

parser = argparse.ArgumentParser(description='Team210 manifest generator tool.')
parser.add_argument('-o', '--output', dest='out')
args, rest = parser.parse_known_args()

if rest == []:
    print('No input files present. Can not do anything.')
    exit()

f = open(rest[0], "rt")
source = f.read()
f.close()
print(rest[0])
ast = pyglsl_parser.parse(source, rest[0], pyglsl_parser.enums.ShaderType.Fragment)
print(ast.functions)