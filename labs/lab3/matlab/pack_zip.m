clear;close;clc;
%Get Parent Folder
current_dir = pwd;
current_vec = regexp(current_dir, '\\', 'split');
current_name = current_vec{end - 1};
zfn = join([current_name, "11913019", "仇琨元"], "_")

%Get File List
fn_mat = dir('.');
fn_tex = dir('../tex');
fn_mat = {fn_mat(3:end).name};
fn_tex = {fn_tex(3:end).name};
fn_mat(contains(fn_mat, [".pdf", ".log"]) == 1) = [];
fn_tex(contains(fn_tex, [".png", ".tex", ".cls"]) == 0) = [];

%Packaging
mkdir("../temp");
mkdir("../temp/matlab");
mkdir("../temp/tex");

for v1 = fn_mat
    copyfile(string(v1), "../temp/matlab");
end

cd("../tex");

for v2 = fn_tex
    copyfile(string(v2), "../temp/tex");
end

copyfile(join([current_name, "pdf"], '.'), join(["../", zfn, ".pdf"], ''))

zip(join(["../", zfn], ''), "temp", "..")
%Cleaning up
rmdir("../temp", 's')
