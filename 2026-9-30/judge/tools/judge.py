#!/usr/bin/env python3
"""Judge one C++ file against the complete 20-case file-I/O test set."""
import argparse,json,subprocess,tempfile
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
TASKS=('circle','jobs','median','dfs')
LIMITS={'circle':2,'jobs':2,'median':5,'dfs':5}

def main():
    p=argparse.ArgumentParser(description='NOIP 风格模拟赛（二）本地评测')
    p.add_argument('source',type=Path)
    p.add_argument('--task',choices=TASKS)
    p.add_argument('--time-factor',type=float,default=2)
    args=p.parse_args()
    task=args.task or args.source.stem
    if task not in TASKS or not args.source.is_file() or args.time_factor<=0:p.error('无效的题目、源码或时间倍数')
    data=ROOT/'judge'
    manifest=json.loads((data/'manifest.json').read_text())
    score=0
    with tempfile.TemporaryDirectory(prefix='noip2-judge-') as d:
        d=Path(d);exe=d/'program'
        ret=subprocess.run(['g++','-O2','-std=c++17',str(args.source.resolve()),'-o',str(exe)],capture_output=True,text=True)
        if ret.returncode:print('编译失败：',ret.stderr[:2500]);return 1
        for item in manifest['tasks'][task]['tests']:
            (d/f'{task}.in').write_bytes((data/item['input']).read_bytes())
            dest=d/f'{task}.out';dest.unlink(missing_ok=True)
            try:
                run=subprocess.run([str(exe)],cwd=d,stdin=subprocess.DEVNULL,stdout=subprocess.DEVNULL,
                                   stderr=subprocess.DEVNULL,timeout=LIMITS[task]*args.time_factor)
                if run.returncode:result='RE'
                elif not dest.is_file():result='无输出文件'
                elif dest.read_bytes().split()==(data/item['answer']).read_bytes().split():
                    result='AC';score+=item['points']
                else:result='WA'
            except subprocess.TimeoutExpired:result='TLE（本机参考）'
            print(f"{task}{item['id']:02}: {result}",flush=True)
    print(f'总分：{score}/100')
    return 0

if __name__=='__main__':raise SystemExit(main())
