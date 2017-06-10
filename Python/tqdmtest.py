# See https://codeclimate.com/github/tqdm/tqdm/examples/simple_examples.py#source

# Basic demo
import tqdm
'''
for i in tqdm.trange(int(1e8)):
    pass
'''
'''
for i in tqdm.trange(int(1e8), miniters=int(1e6), ascii=True,
                     desc="cool", dynamic_ncols=True):
    pass
'''
from tqdm import trange
for i in trange(10):
    for j in trange(int(1e7), leave=False, unit_scale=True):
        pass
